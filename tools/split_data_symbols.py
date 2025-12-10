from argparse import ArgumentParser
from pathlib import Path
import re

"""
A simple script that takes a file with symbols and a starting address as inputs, and generates a new symbols text file
with addresses starting from the input address.

Ex: A file with the symbols
@121 = .sdata2:0x804CD810; // type:object size:0x4 scope:local align:4 data:float
@122 = .sdata2:0x804CD814; // type:object size:0x4 scope:local align:4 data:float

and an input starting address of 0x804ECAA0 will generate symbols in the following manner:
@121 = .sdata2:0X804ECAA0; // type:object size:0x4 scope:local align:4 data:float
@122 = .sdata2:0X804ECAA4; // type:object size:0x4 scope:local align:4 data:float

This was used to map SDK symbol addresses from the demo version to the retail version.
This assumes that the symbol size, alignment, etc in the symbol file is accurate, so use with caution.
"""

SYMBOL_REGEX = re.compile(r"^\s*(?P<name>[^=]+?) (?P<section>.*)(?P<addr>0x[0-9A-Fa-f]+);(?P<extra>.*)$", re.VERBOSE)


def parse_line(line: str):
    sym_match = SYMBOL_REGEX.match(line)
    if not sym_match:
        return None

    return (
        sym_match.group("name"),
        sym_match.group("section"),
        int(sym_match.group("addr"), 16),
        sym_match.group("extra")
    )


def generate_new_data_splits(start_offset: int, symbols_file_path: Path):
    data_split = []

    with open(symbols_file_path, "r") as f:
        lines = f.readlines()
        file_symbols_start_offset = parse_line(lines[0])[2]

        for line in lines:
            name, section, addr, extra = parse_line(line)
            new_offset = start_offset + addr - file_symbols_start_offset
            data_split.append(f"{name}{section}{hex(new_offset).upper()};{extra}")

    return "\n".join(data_split)


def main():
    parser = ArgumentParser(description="Print data splits starting from an input offset, based on data symbols from a completed symbols text file")
    parser.add_argument(
        "start_offset",
        type=str,
        help="Starting offset for new data splits"
    )
    parser.add_argument(
        "symbols_text_file",
        type=Path,
        help="path to text file with data symbols section from symbols.txt"
    )
    parser.add_argument(
        "-o",
        "--output",
        type=Path,
        help="Output file (prints to console if unspecified)",
    )
    args = parser.parse_args()

    data_splits = generate_new_data_splits(int(args.start_offset, 16), args.symbols_text_file)
    if (args.output):
        with open(args.output, "w", encoding="utf-8") as f:
            f.write(data_splits)
    else:
        print(data_splits)


if __name__ == "__main__":
    main()

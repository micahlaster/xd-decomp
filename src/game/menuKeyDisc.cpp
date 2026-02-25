#include <game/menuKeyDisc.hpp>
#include <game/pxdvs/app/floor/floor.hpp>
#include <game/pxdvs/GSAPI/GSres/GSres.hpp>

void menuKeyDiscExit()
{
}

void menuKeyDiscMain()
{
  u32 uVar1 = floorGetCurrentGroupID();
  GSresGetResource(uVar1,0x117f0000);
}
void menuKeyDiscInit()
{
}
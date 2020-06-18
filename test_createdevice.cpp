#include <stdio.h>
#include <windows.h>
#include <d3d9.h>

#include "d3d9hooks.h"
DWORD* get_Direct3DDevice9_vtable();

int main() {
    get_Direct3DDevice9_vtable();
    return 0;   
}

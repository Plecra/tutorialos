// clang defines _MSC_EXTENSIONS but doesn't implement static_assert. LIES
#undef _MSC_EXTENSIONS
#include "Uefi.h"
#include "Protocol/GraphicsOutput.h"

#define ERR(x) if (EFI_ERROR((x))) { return (x); }

EFI_STATUS efi_main(EFI_HANDLE handle __attribute__((unused)), EFI_SYSTEM_TABLE* st) {
  EFI_STATUS status;

  /* clear the screen */
  status = st->ConOut->ClearScreen(st->ConOut);
  ERR(status);

  /* print 'Hello World' */
  status = st->ConOut->OutputString(st->ConOut, u"Hello World");
  ERR(status);

  EFI_GRAPHICS_OUTPUT_PROTOCOL* gop;
  status = st->BootServices->LocateProtocol(&(EFI_GUID) EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID, NULL, (void**)&gop);
  ERR(status);

  EFI_GRAPHICS_OUTPUT_BLT_PIXEL color = {0, 0, 200, 0};
  status = gop->Blt(gop, &color, EfiBltVideoFill, 0, 0, 0, 0, gop->Mode->Info->HorizontalResolution, gop->Mode->Info->VerticalResolution, 0);
  ERR(status);

  status = st->ConOut->OutputString(st->ConOut, u"Hello World");
  ERR(status);


  // st->BootServemices->ExitBootServices(handle, 0);
  for (int i = 0; i < 10000; i++) {
    st->BootServices->Stall(1000 * 1000 * 10);
  }
  return EFI_SUCCESS;
}
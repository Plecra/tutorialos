set "SRC=%cd%"
mkdir build
cd build
mkdir out
clang -I%SRC%/edk2/MdePkg/Include -I%SRC%/edk2/MdePkg/Include/X64 -target x86_64-pc-win32-coff -fno-stack-protector -fshort-wchar -mno-red-zone -c %SRC%\main.c -o main.o
lld-link -subsystem:efi_application -nodefaultlib -dll -entry:efi_main main.o -out:out/main.efi

mkdir .\out\ESP\EFI\BOOT
copy .\out\main.efi .\out\ESP\EFI\BOOT\BOOTX64.EFI
cd ..
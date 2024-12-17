rem in a typical qemu installation, we can grab the ovmf firmware directly.
rem you should also be able to build this from edk2 if you need to.
rem WARNING: The OVMF packaged for windows is incompatible with linux qemu.
copy "C:\Program Files\qemu\share\edk2-x86_64-code.fd" build
"C:\Program Files\qemu\qemu-system-x86_64.exe" -drive if=pflash,format=raw,file=build/edk2-x86_64-code.fd -drive file=fat:rw:build/out/ESP,format=raw
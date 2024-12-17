# tempname: tutorialos

A stripped down microkernel, designed for teaching os concepts in a brief course.



## notes

- single threaded
- full iommu req
- typed mem, with generative type names at runtime
- a scheduler with wakeable tasks
- a high level of direct access to paging
- uefi framebuffer graphics

1. uefi boot
  bootrom packages fat32, (ntfs, ext4) filesystem read drivers, and SCSI, NVMe, SATA, USB BOT transports, along with support for the uefi interfaces (theyre implemented as uefi drivers)
2. get framebuffer
3. get keyboard
4. get block device
5. initialize physical memory allocator
6. construct page tables (and setup init's)
    using typed mem for Allocation(start, len, flags) and RcAllocation for sharing. we only have moving between these buffers. strictly owned by a process, and optionally mapped into vmem.
7. initialize executor
8. start init process (processes defined with executor.add(Task::Ring3Process(ip, pagetable)))
9. run executor

5. init filesystem

we need to especially simplify our input model. we'll use the ps/2 virtualisation to get it online. SIMPLE_TEXT_INPUT_PROTOCOL would be great, but we're working in a freestanding environment, because uefi would simplify many things we're interested in.

- uefi application for efi/boot/bootx64.efi
  - scans for init + fs processes. we like lazy loading but init needs to know how to load exes.



enough of a kernel to run http servers off, with direct access to discrete devices
meaning I actually want to 

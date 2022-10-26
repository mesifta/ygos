# ygos

This project tries to build an operating system from scratch.

So far created
<ul>
    <li>a boot loader</li>
        <ul>
            <li>Printing to screen using BIOS functions</li>
            <li>Creating a gdt</li>
            <li>Switching to 32bit protected mode</li>
            <li>Loading our kernel to memory usig BIOS functions</li>
        </ul> 
    <li>a basic 80x25 vga screen driver</li>
    <li>setting up an IDT</li>
    <li>Remapping the PIC</li>
    <li>a keyboard driver</li>
    <li>a shutdown mechanism</li>
</ul>
    
next on the list is
<ul>
    <li>disk read/write driver</li>
    <li>a basic file system</li>
    <li> and much more...</li>
</ul>

## linux-madcap-msmt

memo

- make menuconfig
 - General setup -> add some identifier to "Local version".
 - and check "Automatically append version information to version string"
- sudo CONCURRENCY_LEVEL=8 make-kpkg --rootcmd fakeroot --initrd --revision=2016XXXX01 kernel_image kernel_headers
- dpkg -i linux-image-3.19.0-SOMEID_2016XXXX01_amd64.deb
- dpkg -i linux-headers-3.19.0-SOMEID_2016XXXX01_amd64.deb
- create symblic links for boot image.
 - cd /
 - sudo ln -sf boot/initrd.img-3.19.0-SOMEID initrd.img
 - sudo ln -sf boot/vmlinuz-3.19.0-SOMEID vmlinuz
 - reboot
- then, madcap drivers can be compiled with OVBENCH=yes

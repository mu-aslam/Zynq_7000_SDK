connect -url tcp:127.0.0.1:3121
source C:/Users/maslam/Desktop/IDLAB/gitHub/documents/Non_PhDworks/FPGAdesign_com/Lec5_EMIO_implementation/vivado/project_1/project_1.sdk/design_1_wrapper_hw_platform_0/ps7_init.tcl
targets -set -filter {name =~"APU" && jtag_cable_name =~ "Digilent Zed 210248A49A6B"} -index 0
loadhw C:/Users/maslam/Desktop/IDLAB/gitHub/documents/Non_PhDworks/FPGAdesign_com/Lec5_EMIO_implementation/vivado/project_1/project_1.sdk/design_1_wrapper_hw_platform_0/system.hdf
targets -set -filter {name =~"APU" && jtag_cable_name =~ "Digilent Zed 210248A49A6B"} -index 0
stop
ps7_init
ps7_post_config
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zed 210248A49A6B"} -index 0
rst -processor
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zed 210248A49A6B"} -index 0
dow C:/Users/maslam/Desktop/IDLAB/gitHub/documents/Non_PhDworks/FPGAdesign_com/Lec5_EMIO_implementation/vivado/project_1/project_1.sdk/test/Debug/test.elf
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zed 210248A49A6B"} -index 0
con

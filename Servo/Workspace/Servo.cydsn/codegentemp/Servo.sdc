# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\Projects\ESD\Servo\Workspace\Servo.cydsn\Servo.cyprj
# Date: Wed, 06 Sep 2017 15:45:57 GMT
#set_units -time ns
create_clock -name {CyILO} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 15.625 -waveform {0 7.8125} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 15.625 -waveform {0 7.8125} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {CyScBoostClk} -period 93.75 -waveform {0 46.875} [list [get_pins {ClockBlock/aclk_glb_0}]]
create_generated_clock -name {UART_2_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 71 139} -nominal_period 1083.3333333333333 [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {UART_3_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 71 139} -nominal_period 1083.3333333333333 [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {UART_1_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 71 139} -nominal_period 1083.3333333333333 [list [get_pins {ClockBlock/dclk_glb_2}]]


# Component constraints for D:\Projects\ESD\Servo\Workspace\Servo.cydsn\TopDesign\PSoC5\TopDesign.cysch
# Project: D:\Projects\ESD\Servo\Workspace\Servo.cydsn\Servo.cyprj
# Date: Wed, 06 Sep 2017 15:45:43 GMT

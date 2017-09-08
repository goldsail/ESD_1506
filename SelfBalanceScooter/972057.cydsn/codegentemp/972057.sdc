# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\kingi\Desktop\972057.cydsn\972057.cyprj
# Date: Thu, 07 Sep 2017 15:22:40 GMT
#set_units -time ns
create_clock -name {ADC_SAR_L_theACLK(routed)} -period 792.45283018867917 -waveform {0 396.22641509434} [list [get_pins {ClockBlock/dclk_0}]]
create_clock -name {ADC_SAR_R_theACLK(routed)} -period 886.79245283018872 -waveform {0 443.396226415094} [list [get_pins {ClockBlock/dclk_1}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 18.867924528301888 -waveform {0 9.43396226415094} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 18.867924528301888 -waveform {0 9.43396226415094} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {ADC_SAR_L_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 43 83} -nominal_period 792.45283018867917 [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {ADC_SAR_R_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 47 95} -nominal_period 886.79245283018872 [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {UART_2_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 59 117} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {UART_3_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 59 117} [list [get_pins {ClockBlock/dclk_glb_3}]]
create_generated_clock -name {UART_1_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 59 117} [list [get_pins {ClockBlock/dclk_glb_4}]]
create_generated_clock -name {UART_6_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 691 1381} -nominal_period 13018.867924528302 [list [get_pins {ClockBlock/dclk_glb_5}]]


# Component constraints for C:\Users\kingi\Desktop\972057.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\kingi\Desktop\972057.cydsn\972057.cyprj
# Date: Thu, 07 Sep 2017 15:22:30 GMT

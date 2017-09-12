
module kernel (
	clk_clk,
	ir_1506_conduit_end_0_export,
	lcd_1506_conduit_end_0_export_data,
	lcd_1506_conduit_end_0_export_rw,
	lcd_1506_conduit_end_0_export_en,
	lcd_1506_conduit_end_0_export_rs,
	lcd_1506_conduit_end_0_export_blon,
	lcd_1506_conduit_end_0_export_on,
	new_sdram_controller_wire_addr,
	new_sdram_controller_wire_ba,
	new_sdram_controller_wire_cas_n,
	new_sdram_controller_wire_cke,
	new_sdram_controller_wire_cs_n,
	new_sdram_controller_wire_dq,
	new_sdram_controller_wire_dqm,
	new_sdram_controller_wire_ras_n,
	new_sdram_controller_wire_we_n,
	pio_0_external_connection_export,
	pio_1_external_connection_export,
	pio_2_external_connection_export,
	pio_3_external_connection_export,
	pio_4_external_connection_export,
	pio_5_external_connection_export,
	pio_6_external_connection_export,
	pio_7_external_connection_export,
	reset_reset_n,
	user_gio_pwm_0_conduit_end_0_export,
	user_gio_pwm_10_conduit_end_0_export,
	user_gio_pwm_11_conduit_end_0_export,
	user_gio_pwm_12_conduit_end_0_export,
	user_gio_pwm_13_conduit_end_0_export,
	user_gio_pwm_14_conduit_end_0_export,
	user_gio_pwm_15_conduit_end_0_export,
	user_gio_pwm_16_conduit_end_0_export,
	user_gio_pwm_17_conduit_end_0_export,
	user_gio_pwm_1_conduit_end_0_export,
	user_gio_pwm_2_conduit_end_0_export,
	user_gio_pwm_3_conduit_end_0_export,
	user_gio_pwm_4_conduit_end_0_export,
	user_gio_pwm_5_conduit_end_0_export,
	user_gio_pwm_6_conduit_end_0_export,
	user_gio_pwm_7_conduit_end_0_export,
	user_gio_pwm_8_conduit_end_0_export,
	user_gio_pwm_9_conduit_end_0_export);	

	input		clk_clk;
	input		ir_1506_conduit_end_0_export;
	inout	[7:0]	lcd_1506_conduit_end_0_export_data;
	output		lcd_1506_conduit_end_0_export_rw;
	output		lcd_1506_conduit_end_0_export_en;
	output		lcd_1506_conduit_end_0_export_rs;
	output		lcd_1506_conduit_end_0_export_blon;
	output		lcd_1506_conduit_end_0_export_on;
	output	[12:0]	new_sdram_controller_wire_addr;
	output	[1:0]	new_sdram_controller_wire_ba;
	output		new_sdram_controller_wire_cas_n;
	output		new_sdram_controller_wire_cke;
	output		new_sdram_controller_wire_cs_n;
	inout	[31:0]	new_sdram_controller_wire_dq;
	output	[3:0]	new_sdram_controller_wire_dqm;
	output		new_sdram_controller_wire_ras_n;
	output		new_sdram_controller_wire_we_n;
	output		pio_0_external_connection_export;
	output		pio_1_external_connection_export;
	output		pio_2_external_connection_export;
	output		pio_3_external_connection_export;
	output		pio_4_external_connection_export;
	output		pio_5_external_connection_export;
	output		pio_6_external_connection_export;
	output		pio_7_external_connection_export;
	input		reset_reset_n;
	output		user_gio_pwm_0_conduit_end_0_export;
	output		user_gio_pwm_10_conduit_end_0_export;
	output		user_gio_pwm_11_conduit_end_0_export;
	output		user_gio_pwm_12_conduit_end_0_export;
	output		user_gio_pwm_13_conduit_end_0_export;
	output		user_gio_pwm_14_conduit_end_0_export;
	output		user_gio_pwm_15_conduit_end_0_export;
	output		user_gio_pwm_16_conduit_end_0_export;
	output		user_gio_pwm_17_conduit_end_0_export;
	output		user_gio_pwm_1_conduit_end_0_export;
	output		user_gio_pwm_2_conduit_end_0_export;
	output		user_gio_pwm_3_conduit_end_0_export;
	output		user_gio_pwm_4_conduit_end_0_export;
	output		user_gio_pwm_5_conduit_end_0_export;
	output		user_gio_pwm_6_conduit_end_0_export;
	output		user_gio_pwm_7_conduit_end_0_export;
	output		user_gio_pwm_8_conduit_end_0_export;
	output		user_gio_pwm_9_conduit_end_0_export;
endmodule

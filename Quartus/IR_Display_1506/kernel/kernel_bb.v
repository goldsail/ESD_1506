
module kernel (
	clk_clk,
	ir_1506_0_conduit_end_0_export_ir,
	lcd_1506_0_conduit_end_0_export_data,
	lcd_1506_0_conduit_end_0_export_rw,
	lcd_1506_0_conduit_end_0_export_en,
	lcd_1506_0_conduit_end_0_export_rs,
	lcd_1506_0_conduit_end_0_export_blon,
	lcd_1506_0_conduit_end_0_export_on,
	new_sdram_controller_0_wire_addr,
	new_sdram_controller_0_wire_ba,
	new_sdram_controller_0_wire_cas_n,
	new_sdram_controller_0_wire_cke,
	new_sdram_controller_0_wire_cs_n,
	new_sdram_controller_0_wire_dq,
	new_sdram_controller_0_wire_dqm,
	new_sdram_controller_0_wire_ras_n,
	new_sdram_controller_0_wire_we_n,
	reset_reset_n);	

	input		clk_clk;
	input		ir_1506_0_conduit_end_0_export_ir;
	inout	[7:0]	lcd_1506_0_conduit_end_0_export_data;
	output		lcd_1506_0_conduit_end_0_export_rw;
	output		lcd_1506_0_conduit_end_0_export_en;
	output		lcd_1506_0_conduit_end_0_export_rs;
	output		lcd_1506_0_conduit_end_0_export_blon;
	output		lcd_1506_0_conduit_end_0_export_on;
	output	[12:0]	new_sdram_controller_0_wire_addr;
	output	[1:0]	new_sdram_controller_0_wire_ba;
	output		new_sdram_controller_0_wire_cas_n;
	output		new_sdram_controller_0_wire_cke;
	output		new_sdram_controller_0_wire_cs_n;
	inout	[31:0]	new_sdram_controller_0_wire_dq;
	output	[3:0]	new_sdram_controller_0_wire_dqm;
	output		new_sdram_controller_0_wire_ras_n;
	output		new_sdram_controller_0_wire_we_n;
	input		reset_reset_n;
endmodule

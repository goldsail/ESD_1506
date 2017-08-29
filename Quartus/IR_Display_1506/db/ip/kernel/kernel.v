// kernel.v

// Generated using ACDS version 15.0 145

`timescale 1 ps / 1 ps
module kernel (
		input  wire        clk_clk,                              //                         clk.clk
		input  wire        ir_1506_0_conduit_end_0_export_ir,    //     ir_1506_0_conduit_end_0.export_ir
		inout  wire [7:0]  lcd_1506_0_conduit_end_0_export_data, //    lcd_1506_0_conduit_end_0.export_data
		output wire        lcd_1506_0_conduit_end_0_export_rw,   //                            .export_rw
		output wire        lcd_1506_0_conduit_end_0_export_en,   //                            .export_en
		output wire        lcd_1506_0_conduit_end_0_export_rs,   //                            .export_rs
		output wire        lcd_1506_0_conduit_end_0_export_blon, //                            .export_blon
		output wire        lcd_1506_0_conduit_end_0_export_on,   //                            .export_on
		output wire [12:0] new_sdram_controller_0_wire_addr,     // new_sdram_controller_0_wire.addr
		output wire [1:0]  new_sdram_controller_0_wire_ba,       //                            .ba
		output wire        new_sdram_controller_0_wire_cas_n,    //                            .cas_n
		output wire        new_sdram_controller_0_wire_cke,      //                            .cke
		output wire        new_sdram_controller_0_wire_cs_n,     //                            .cs_n
		inout  wire [31:0] new_sdram_controller_0_wire_dq,       //                            .dq
		output wire [3:0]  new_sdram_controller_0_wire_dqm,      //                            .dqm
		output wire        new_sdram_controller_0_wire_ras_n,    //                            .ras_n
		output wire        new_sdram_controller_0_wire_we_n,     //                            .we_n
		input  wire        reset_reset_n                         //                       reset.reset_n
	);

	wire  [31:0] nios2_gen2_0_data_master_readdata;                           // mm_interconnect_0:nios2_gen2_0_data_master_readdata -> nios2_gen2_0:d_readdata
	wire         nios2_gen2_0_data_master_waitrequest;                        // mm_interconnect_0:nios2_gen2_0_data_master_waitrequest -> nios2_gen2_0:d_waitrequest
	wire         nios2_gen2_0_data_master_debugaccess;                        // nios2_gen2_0:debug_mem_slave_debugaccess_to_roms -> mm_interconnect_0:nios2_gen2_0_data_master_debugaccess
	wire  [28:0] nios2_gen2_0_data_master_address;                            // nios2_gen2_0:d_address -> mm_interconnect_0:nios2_gen2_0_data_master_address
	wire   [3:0] nios2_gen2_0_data_master_byteenable;                         // nios2_gen2_0:d_byteenable -> mm_interconnect_0:nios2_gen2_0_data_master_byteenable
	wire         nios2_gen2_0_data_master_read;                               // nios2_gen2_0:d_read -> mm_interconnect_0:nios2_gen2_0_data_master_read
	wire         nios2_gen2_0_data_master_write;                              // nios2_gen2_0:d_write -> mm_interconnect_0:nios2_gen2_0_data_master_write
	wire  [31:0] nios2_gen2_0_data_master_writedata;                          // nios2_gen2_0:d_writedata -> mm_interconnect_0:nios2_gen2_0_data_master_writedata
	wire  [31:0] nios2_gen2_0_instruction_master_readdata;                    // mm_interconnect_0:nios2_gen2_0_instruction_master_readdata -> nios2_gen2_0:i_readdata
	wire         nios2_gen2_0_instruction_master_waitrequest;                 // mm_interconnect_0:nios2_gen2_0_instruction_master_waitrequest -> nios2_gen2_0:i_waitrequest
	wire  [28:0] nios2_gen2_0_instruction_master_address;                     // nios2_gen2_0:i_address -> mm_interconnect_0:nios2_gen2_0_instruction_master_address
	wire         nios2_gen2_0_instruction_master_read;                        // nios2_gen2_0:i_read -> mm_interconnect_0:nios2_gen2_0_instruction_master_read
	wire         nios2_gen2_0_instruction_master_readdatavalid;               // mm_interconnect_0:nios2_gen2_0_instruction_master_readdatavalid -> nios2_gen2_0:i_readdatavalid
	wire         mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_chipselect;  // mm_interconnect_0:jtag_uart_0_avalon_jtag_slave_chipselect -> jtag_uart_0:av_chipselect
	wire  [31:0] mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_readdata;    // jtag_uart_0:av_readdata -> mm_interconnect_0:jtag_uart_0_avalon_jtag_slave_readdata
	wire         mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_waitrequest; // jtag_uart_0:av_waitrequest -> mm_interconnect_0:jtag_uart_0_avalon_jtag_slave_waitrequest
	wire   [0:0] mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_address;     // mm_interconnect_0:jtag_uart_0_avalon_jtag_slave_address -> jtag_uart_0:av_address
	wire         mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_read;        // mm_interconnect_0:jtag_uart_0_avalon_jtag_slave_read -> jtag_uart_0:av_read_n
	wire         mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_write;       // mm_interconnect_0:jtag_uart_0_avalon_jtag_slave_write -> jtag_uart_0:av_write_n
	wire  [31:0] mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_writedata;   // mm_interconnect_0:jtag_uart_0_avalon_jtag_slave_writedata -> jtag_uart_0:av_writedata
	wire         mm_interconnect_0_ir_1506_0_avalon_slave_0_chipselect;       // mm_interconnect_0:IR_1506_0_avalon_slave_0_chipselect -> IR_1506_0:avs_chipselect
	wire  [31:0] mm_interconnect_0_ir_1506_0_avalon_slave_0_readdata;         // IR_1506_0:avs_readdata -> mm_interconnect_0:IR_1506_0_avalon_slave_0_readdata
	wire   [4:0] mm_interconnect_0_ir_1506_0_avalon_slave_0_address;          // mm_interconnect_0:IR_1506_0_avalon_slave_0_address -> IR_1506_0:avs_address
	wire         mm_interconnect_0_ir_1506_0_avalon_slave_0_read;             // mm_interconnect_0:IR_1506_0_avalon_slave_0_read -> IR_1506_0:avs_read
	wire         mm_interconnect_0_ir_1506_0_avalon_slave_0_write;            // mm_interconnect_0:IR_1506_0_avalon_slave_0_write -> IR_1506_0:avs_write
	wire  [31:0] mm_interconnect_0_ir_1506_0_avalon_slave_0_writedata;        // mm_interconnect_0:IR_1506_0_avalon_slave_0_writedata -> IR_1506_0:avs_writedata
	wire         mm_interconnect_0_lcd_1506_0_avalon_slave_0_chipselect;      // mm_interconnect_0:LCD_1506_0_avalon_slave_0_chipselect -> LCD_1506_0:avs_chipselect
	wire  [31:0] mm_interconnect_0_lcd_1506_0_avalon_slave_0_readdata;        // LCD_1506_0:avs_readdata -> mm_interconnect_0:LCD_1506_0_avalon_slave_0_readdata
	wire   [4:0] mm_interconnect_0_lcd_1506_0_avalon_slave_0_address;         // mm_interconnect_0:LCD_1506_0_avalon_slave_0_address -> LCD_1506_0:avs_address
	wire         mm_interconnect_0_lcd_1506_0_avalon_slave_0_read;            // mm_interconnect_0:LCD_1506_0_avalon_slave_0_read -> LCD_1506_0:avs_read
	wire         mm_interconnect_0_lcd_1506_0_avalon_slave_0_write;           // mm_interconnect_0:LCD_1506_0_avalon_slave_0_write -> LCD_1506_0:avs_write
	wire  [31:0] mm_interconnect_0_lcd_1506_0_avalon_slave_0_writedata;       // mm_interconnect_0:LCD_1506_0_avalon_slave_0_writedata -> LCD_1506_0:avs_writedata
	wire  [31:0] mm_interconnect_0_sysid_qsys_0_control_slave_readdata;       // sysid_qsys_0:readdata -> mm_interconnect_0:sysid_qsys_0_control_slave_readdata
	wire   [0:0] mm_interconnect_0_sysid_qsys_0_control_slave_address;        // mm_interconnect_0:sysid_qsys_0_control_slave_address -> sysid_qsys_0:address
	wire  [31:0] mm_interconnect_0_nios2_gen2_0_debug_mem_slave_readdata;     // nios2_gen2_0:debug_mem_slave_readdata -> mm_interconnect_0:nios2_gen2_0_debug_mem_slave_readdata
	wire         mm_interconnect_0_nios2_gen2_0_debug_mem_slave_waitrequest;  // nios2_gen2_0:debug_mem_slave_waitrequest -> mm_interconnect_0:nios2_gen2_0_debug_mem_slave_waitrequest
	wire         mm_interconnect_0_nios2_gen2_0_debug_mem_slave_debugaccess;  // mm_interconnect_0:nios2_gen2_0_debug_mem_slave_debugaccess -> nios2_gen2_0:debug_mem_slave_debugaccess
	wire   [8:0] mm_interconnect_0_nios2_gen2_0_debug_mem_slave_address;      // mm_interconnect_0:nios2_gen2_0_debug_mem_slave_address -> nios2_gen2_0:debug_mem_slave_address
	wire         mm_interconnect_0_nios2_gen2_0_debug_mem_slave_read;         // mm_interconnect_0:nios2_gen2_0_debug_mem_slave_read -> nios2_gen2_0:debug_mem_slave_read
	wire   [3:0] mm_interconnect_0_nios2_gen2_0_debug_mem_slave_byteenable;   // mm_interconnect_0:nios2_gen2_0_debug_mem_slave_byteenable -> nios2_gen2_0:debug_mem_slave_byteenable
	wire         mm_interconnect_0_nios2_gen2_0_debug_mem_slave_write;        // mm_interconnect_0:nios2_gen2_0_debug_mem_slave_write -> nios2_gen2_0:debug_mem_slave_write
	wire  [31:0] mm_interconnect_0_nios2_gen2_0_debug_mem_slave_writedata;    // mm_interconnect_0:nios2_gen2_0_debug_mem_slave_writedata -> nios2_gen2_0:debug_mem_slave_writedata
	wire         mm_interconnect_0_new_sdram_controller_0_s1_chipselect;      // mm_interconnect_0:new_sdram_controller_0_s1_chipselect -> new_sdram_controller_0:az_cs
	wire  [31:0] mm_interconnect_0_new_sdram_controller_0_s1_readdata;        // new_sdram_controller_0:za_data -> mm_interconnect_0:new_sdram_controller_0_s1_readdata
	wire         mm_interconnect_0_new_sdram_controller_0_s1_waitrequest;     // new_sdram_controller_0:za_waitrequest -> mm_interconnect_0:new_sdram_controller_0_s1_waitrequest
	wire  [24:0] mm_interconnect_0_new_sdram_controller_0_s1_address;         // mm_interconnect_0:new_sdram_controller_0_s1_address -> new_sdram_controller_0:az_addr
	wire         mm_interconnect_0_new_sdram_controller_0_s1_read;            // mm_interconnect_0:new_sdram_controller_0_s1_read -> new_sdram_controller_0:az_rd_n
	wire   [3:0] mm_interconnect_0_new_sdram_controller_0_s1_byteenable;      // mm_interconnect_0:new_sdram_controller_0_s1_byteenable -> new_sdram_controller_0:az_be_n
	wire         mm_interconnect_0_new_sdram_controller_0_s1_readdatavalid;   // new_sdram_controller_0:za_valid -> mm_interconnect_0:new_sdram_controller_0_s1_readdatavalid
	wire         mm_interconnect_0_new_sdram_controller_0_s1_write;           // mm_interconnect_0:new_sdram_controller_0_s1_write -> new_sdram_controller_0:az_wr_n
	wire  [31:0] mm_interconnect_0_new_sdram_controller_0_s1_writedata;       // mm_interconnect_0:new_sdram_controller_0_s1_writedata -> new_sdram_controller_0:az_data
	wire         irq_mapper_receiver0_irq;                                    // IR_1506_0:ins_irq -> irq_mapper:receiver0_irq
	wire         irq_mapper_receiver1_irq;                                    // jtag_uart_0:av_irq -> irq_mapper:receiver1_irq
	wire  [31:0] nios2_gen2_0_irq_irq;                                        // irq_mapper:sender_irq -> nios2_gen2_0:irq
	wire         rst_controller_reset_out_reset;                              // rst_controller:reset_out -> [IR_1506_0:csi_RST_N, LCD_1506_0:csi_RST_N, irq_mapper:reset, jtag_uart_0:rst_n, mm_interconnect_0:nios2_gen2_0_reset_reset_bridge_in_reset_reset, new_sdram_controller_0:reset_n, nios2_gen2_0:reset_n, rst_translator:in_reset, sysid_qsys_0:reset_n]
	wire         rst_controller_reset_out_reset_req;                          // rst_controller:reset_req -> [nios2_gen2_0:reset_req, rst_translator:reset_req_in]
	wire         nios2_gen2_0_debug_reset_request_reset;                      // nios2_gen2_0:debug_reset_request -> rst_controller:reset_in1

	IR_Module ir_1506_0 (
		.csi_CLK        (clk_clk),                                               //              clock.clk
		.csi_RST_N      (~rst_controller_reset_out_reset),                       //        clock_reset.reset_n
		.avs_chipselect (mm_interconnect_0_ir_1506_0_avalon_slave_0_chipselect), //     avalon_slave_0.chipselect
		.avs_address    (mm_interconnect_0_ir_1506_0_avalon_slave_0_address),    //                   .address
		.avs_read       (mm_interconnect_0_ir_1506_0_avalon_slave_0_read),       //                   .read
		.avs_readdata   (mm_interconnect_0_ir_1506_0_avalon_slave_0_readdata),   //                   .readdata
		.avs_write      (mm_interconnect_0_ir_1506_0_avalon_slave_0_write),      //                   .write
		.avs_writedata  (mm_interconnect_0_ir_1506_0_avalon_slave_0_writedata),  //                   .writedata
		.ins_irq        (irq_mapper_receiver0_irq),                              // interrupt_sender_0.irq
		.coe_iIRDA      (ir_1506_0_conduit_end_0_export_ir)                      //      conduit_end_0.export_ir
	);

	LCD_Module lcd_1506_0 (
		.csi_CLK        (clk_clk),                                                //          clock.clk
		.csi_RST_N      (~rst_controller_reset_out_reset),                        //    clock_reset.reset_n
		.avs_chipselect (mm_interconnect_0_lcd_1506_0_avalon_slave_0_chipselect), // avalon_slave_0.chipselect
		.avs_address    (mm_interconnect_0_lcd_1506_0_avalon_slave_0_address),    //               .address
		.avs_read       (mm_interconnect_0_lcd_1506_0_avalon_slave_0_read),       //               .read
		.avs_readdata   (mm_interconnect_0_lcd_1506_0_avalon_slave_0_readdata),   //               .readdata
		.avs_write      (mm_interconnect_0_lcd_1506_0_avalon_slave_0_write),      //               .write
		.avs_writedata  (mm_interconnect_0_lcd_1506_0_avalon_slave_0_writedata),  //               .writedata
		.coe_LCD_DATA   (lcd_1506_0_conduit_end_0_export_data),                   //  conduit_end_0.export_data
		.coe_LCD_RW     (lcd_1506_0_conduit_end_0_export_rw),                     //               .export_rw
		.coe_LCD_EN     (lcd_1506_0_conduit_end_0_export_en),                     //               .export_en
		.coe_LCD_RS     (lcd_1506_0_conduit_end_0_export_rs),                     //               .export_rs
		.coe_LCD_BLON   (lcd_1506_0_conduit_end_0_export_blon),                   //               .export_blon
		.coe_LCD_ON     (lcd_1506_0_conduit_end_0_export_on)                      //               .export_on
	);

	kernel_jtag_uart_0 jtag_uart_0 (
		.clk            (clk_clk),                                                     //               clk.clk
		.rst_n          (~rst_controller_reset_out_reset),                             //             reset.reset_n
		.av_chipselect  (mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_chipselect),  // avalon_jtag_slave.chipselect
		.av_address     (mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_address),     //                  .address
		.av_read_n      (~mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_read),       //                  .read_n
		.av_readdata    (mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_readdata),    //                  .readdata
		.av_write_n     (~mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_write),      //                  .write_n
		.av_writedata   (mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_writedata),   //                  .writedata
		.av_waitrequest (mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_waitrequest), //                  .waitrequest
		.av_irq         (irq_mapper_receiver1_irq)                                     //               irq.irq
	);

	kernel_new_sdram_controller_0 new_sdram_controller_0 (
		.clk            (clk_clk),                                                   //   clk.clk
		.reset_n        (~rst_controller_reset_out_reset),                           // reset.reset_n
		.az_addr        (mm_interconnect_0_new_sdram_controller_0_s1_address),       //    s1.address
		.az_be_n        (~mm_interconnect_0_new_sdram_controller_0_s1_byteenable),   //      .byteenable_n
		.az_cs          (mm_interconnect_0_new_sdram_controller_0_s1_chipselect),    //      .chipselect
		.az_data        (mm_interconnect_0_new_sdram_controller_0_s1_writedata),     //      .writedata
		.az_rd_n        (~mm_interconnect_0_new_sdram_controller_0_s1_read),         //      .read_n
		.az_wr_n        (~mm_interconnect_0_new_sdram_controller_0_s1_write),        //      .write_n
		.za_data        (mm_interconnect_0_new_sdram_controller_0_s1_readdata),      //      .readdata
		.za_valid       (mm_interconnect_0_new_sdram_controller_0_s1_readdatavalid), //      .readdatavalid
		.za_waitrequest (mm_interconnect_0_new_sdram_controller_0_s1_waitrequest),   //      .waitrequest
		.zs_addr        (new_sdram_controller_0_wire_addr),                          //  wire.export
		.zs_ba          (new_sdram_controller_0_wire_ba),                            //      .export
		.zs_cas_n       (new_sdram_controller_0_wire_cas_n),                         //      .export
		.zs_cke         (new_sdram_controller_0_wire_cke),                           //      .export
		.zs_cs_n        (new_sdram_controller_0_wire_cs_n),                          //      .export
		.zs_dq          (new_sdram_controller_0_wire_dq),                            //      .export
		.zs_dqm         (new_sdram_controller_0_wire_dqm),                           //      .export
		.zs_ras_n       (new_sdram_controller_0_wire_ras_n),                         //      .export
		.zs_we_n        (new_sdram_controller_0_wire_we_n)                           //      .export
	);

	kernel_nios2_gen2_0 nios2_gen2_0 (
		.clk                                 (clk_clk),                                                    //                       clk.clk
		.reset_n                             (~rst_controller_reset_out_reset),                            //                     reset.reset_n
		.reset_req                           (rst_controller_reset_out_reset_req),                         //                          .reset_req
		.d_address                           (nios2_gen2_0_data_master_address),                           //               data_master.address
		.d_byteenable                        (nios2_gen2_0_data_master_byteenable),                        //                          .byteenable
		.d_read                              (nios2_gen2_0_data_master_read),                              //                          .read
		.d_readdata                          (nios2_gen2_0_data_master_readdata),                          //                          .readdata
		.d_waitrequest                       (nios2_gen2_0_data_master_waitrequest),                       //                          .waitrequest
		.d_write                             (nios2_gen2_0_data_master_write),                             //                          .write
		.d_writedata                         (nios2_gen2_0_data_master_writedata),                         //                          .writedata
		.debug_mem_slave_debugaccess_to_roms (nios2_gen2_0_data_master_debugaccess),                       //                          .debugaccess
		.i_address                           (nios2_gen2_0_instruction_master_address),                    //        instruction_master.address
		.i_read                              (nios2_gen2_0_instruction_master_read),                       //                          .read
		.i_readdata                          (nios2_gen2_0_instruction_master_readdata),                   //                          .readdata
		.i_waitrequest                       (nios2_gen2_0_instruction_master_waitrequest),                //                          .waitrequest
		.i_readdatavalid                     (nios2_gen2_0_instruction_master_readdatavalid),              //                          .readdatavalid
		.irq                                 (nios2_gen2_0_irq_irq),                                       //                       irq.irq
		.debug_reset_request                 (nios2_gen2_0_debug_reset_request_reset),                     //       debug_reset_request.reset
		.debug_mem_slave_address             (mm_interconnect_0_nios2_gen2_0_debug_mem_slave_address),     //           debug_mem_slave.address
		.debug_mem_slave_byteenable          (mm_interconnect_0_nios2_gen2_0_debug_mem_slave_byteenable),  //                          .byteenable
		.debug_mem_slave_debugaccess         (mm_interconnect_0_nios2_gen2_0_debug_mem_slave_debugaccess), //                          .debugaccess
		.debug_mem_slave_read                (mm_interconnect_0_nios2_gen2_0_debug_mem_slave_read),        //                          .read
		.debug_mem_slave_readdata            (mm_interconnect_0_nios2_gen2_0_debug_mem_slave_readdata),    //                          .readdata
		.debug_mem_slave_waitrequest         (mm_interconnect_0_nios2_gen2_0_debug_mem_slave_waitrequest), //                          .waitrequest
		.debug_mem_slave_write               (mm_interconnect_0_nios2_gen2_0_debug_mem_slave_write),       //                          .write
		.debug_mem_slave_writedata           (mm_interconnect_0_nios2_gen2_0_debug_mem_slave_writedata),   //                          .writedata
		.dummy_ci_port                       ()                                                            // custom_instruction_master.readra
	);

	kernel_sysid_qsys_0 sysid_qsys_0 (
		.clock    (clk_clk),                                               //           clk.clk
		.reset_n  (~rst_controller_reset_out_reset),                       //         reset.reset_n
		.readdata (mm_interconnect_0_sysid_qsys_0_control_slave_readdata), // control_slave.readdata
		.address  (mm_interconnect_0_sysid_qsys_0_control_slave_address)   //              .address
	);

	kernel_mm_interconnect_0 mm_interconnect_0 (
		.clk_0_clk_clk                                  (clk_clk),                                                     //                                clk_0_clk.clk
		.nios2_gen2_0_reset_reset_bridge_in_reset_reset (rst_controller_reset_out_reset),                              // nios2_gen2_0_reset_reset_bridge_in_reset.reset
		.nios2_gen2_0_data_master_address               (nios2_gen2_0_data_master_address),                            //                 nios2_gen2_0_data_master.address
		.nios2_gen2_0_data_master_waitrequest           (nios2_gen2_0_data_master_waitrequest),                        //                                         .waitrequest
		.nios2_gen2_0_data_master_byteenable            (nios2_gen2_0_data_master_byteenable),                         //                                         .byteenable
		.nios2_gen2_0_data_master_read                  (nios2_gen2_0_data_master_read),                               //                                         .read
		.nios2_gen2_0_data_master_readdata              (nios2_gen2_0_data_master_readdata),                           //                                         .readdata
		.nios2_gen2_0_data_master_write                 (nios2_gen2_0_data_master_write),                              //                                         .write
		.nios2_gen2_0_data_master_writedata             (nios2_gen2_0_data_master_writedata),                          //                                         .writedata
		.nios2_gen2_0_data_master_debugaccess           (nios2_gen2_0_data_master_debugaccess),                        //                                         .debugaccess
		.nios2_gen2_0_instruction_master_address        (nios2_gen2_0_instruction_master_address),                     //          nios2_gen2_0_instruction_master.address
		.nios2_gen2_0_instruction_master_waitrequest    (nios2_gen2_0_instruction_master_waitrequest),                 //                                         .waitrequest
		.nios2_gen2_0_instruction_master_read           (nios2_gen2_0_instruction_master_read),                        //                                         .read
		.nios2_gen2_0_instruction_master_readdata       (nios2_gen2_0_instruction_master_readdata),                    //                                         .readdata
		.nios2_gen2_0_instruction_master_readdatavalid  (nios2_gen2_0_instruction_master_readdatavalid),               //                                         .readdatavalid
		.IR_1506_0_avalon_slave_0_address               (mm_interconnect_0_ir_1506_0_avalon_slave_0_address),          //                 IR_1506_0_avalon_slave_0.address
		.IR_1506_0_avalon_slave_0_write                 (mm_interconnect_0_ir_1506_0_avalon_slave_0_write),            //                                         .write
		.IR_1506_0_avalon_slave_0_read                  (mm_interconnect_0_ir_1506_0_avalon_slave_0_read),             //                                         .read
		.IR_1506_0_avalon_slave_0_readdata              (mm_interconnect_0_ir_1506_0_avalon_slave_0_readdata),         //                                         .readdata
		.IR_1506_0_avalon_slave_0_writedata             (mm_interconnect_0_ir_1506_0_avalon_slave_0_writedata),        //                                         .writedata
		.IR_1506_0_avalon_slave_0_chipselect            (mm_interconnect_0_ir_1506_0_avalon_slave_0_chipselect),       //                                         .chipselect
		.jtag_uart_0_avalon_jtag_slave_address          (mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_address),     //            jtag_uart_0_avalon_jtag_slave.address
		.jtag_uart_0_avalon_jtag_slave_write            (mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_write),       //                                         .write
		.jtag_uart_0_avalon_jtag_slave_read             (mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_read),        //                                         .read
		.jtag_uart_0_avalon_jtag_slave_readdata         (mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_readdata),    //                                         .readdata
		.jtag_uart_0_avalon_jtag_slave_writedata        (mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_writedata),   //                                         .writedata
		.jtag_uart_0_avalon_jtag_slave_waitrequest      (mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_waitrequest), //                                         .waitrequest
		.jtag_uart_0_avalon_jtag_slave_chipselect       (mm_interconnect_0_jtag_uart_0_avalon_jtag_slave_chipselect),  //                                         .chipselect
		.LCD_1506_0_avalon_slave_0_address              (mm_interconnect_0_lcd_1506_0_avalon_slave_0_address),         //                LCD_1506_0_avalon_slave_0.address
		.LCD_1506_0_avalon_slave_0_write                (mm_interconnect_0_lcd_1506_0_avalon_slave_0_write),           //                                         .write
		.LCD_1506_0_avalon_slave_0_read                 (mm_interconnect_0_lcd_1506_0_avalon_slave_0_read),            //                                         .read
		.LCD_1506_0_avalon_slave_0_readdata             (mm_interconnect_0_lcd_1506_0_avalon_slave_0_readdata),        //                                         .readdata
		.LCD_1506_0_avalon_slave_0_writedata            (mm_interconnect_0_lcd_1506_0_avalon_slave_0_writedata),       //                                         .writedata
		.LCD_1506_0_avalon_slave_0_chipselect           (mm_interconnect_0_lcd_1506_0_avalon_slave_0_chipselect),      //                                         .chipselect
		.new_sdram_controller_0_s1_address              (mm_interconnect_0_new_sdram_controller_0_s1_address),         //                new_sdram_controller_0_s1.address
		.new_sdram_controller_0_s1_write                (mm_interconnect_0_new_sdram_controller_0_s1_write),           //                                         .write
		.new_sdram_controller_0_s1_read                 (mm_interconnect_0_new_sdram_controller_0_s1_read),            //                                         .read
		.new_sdram_controller_0_s1_readdata             (mm_interconnect_0_new_sdram_controller_0_s1_readdata),        //                                         .readdata
		.new_sdram_controller_0_s1_writedata            (mm_interconnect_0_new_sdram_controller_0_s1_writedata),       //                                         .writedata
		.new_sdram_controller_0_s1_byteenable           (mm_interconnect_0_new_sdram_controller_0_s1_byteenable),      //                                         .byteenable
		.new_sdram_controller_0_s1_readdatavalid        (mm_interconnect_0_new_sdram_controller_0_s1_readdatavalid),   //                                         .readdatavalid
		.new_sdram_controller_0_s1_waitrequest          (mm_interconnect_0_new_sdram_controller_0_s1_waitrequest),     //                                         .waitrequest
		.new_sdram_controller_0_s1_chipselect           (mm_interconnect_0_new_sdram_controller_0_s1_chipselect),      //                                         .chipselect
		.nios2_gen2_0_debug_mem_slave_address           (mm_interconnect_0_nios2_gen2_0_debug_mem_slave_address),      //             nios2_gen2_0_debug_mem_slave.address
		.nios2_gen2_0_debug_mem_slave_write             (mm_interconnect_0_nios2_gen2_0_debug_mem_slave_write),        //                                         .write
		.nios2_gen2_0_debug_mem_slave_read              (mm_interconnect_0_nios2_gen2_0_debug_mem_slave_read),         //                                         .read
		.nios2_gen2_0_debug_mem_slave_readdata          (mm_interconnect_0_nios2_gen2_0_debug_mem_slave_readdata),     //                                         .readdata
		.nios2_gen2_0_debug_mem_slave_writedata         (mm_interconnect_0_nios2_gen2_0_debug_mem_slave_writedata),    //                                         .writedata
		.nios2_gen2_0_debug_mem_slave_byteenable        (mm_interconnect_0_nios2_gen2_0_debug_mem_slave_byteenable),   //                                         .byteenable
		.nios2_gen2_0_debug_mem_slave_waitrequest       (mm_interconnect_0_nios2_gen2_0_debug_mem_slave_waitrequest),  //                                         .waitrequest
		.nios2_gen2_0_debug_mem_slave_debugaccess       (mm_interconnect_0_nios2_gen2_0_debug_mem_slave_debugaccess),  //                                         .debugaccess
		.sysid_qsys_0_control_slave_address             (mm_interconnect_0_sysid_qsys_0_control_slave_address),        //               sysid_qsys_0_control_slave.address
		.sysid_qsys_0_control_slave_readdata            (mm_interconnect_0_sysid_qsys_0_control_slave_readdata)        //                                         .readdata
	);

	kernel_irq_mapper irq_mapper (
		.clk           (clk_clk),                        //       clk.clk
		.reset         (rst_controller_reset_out_reset), // clk_reset.reset
		.receiver0_irq (irq_mapper_receiver0_irq),       // receiver0.irq
		.receiver1_irq (irq_mapper_receiver1_irq),       // receiver1.irq
		.sender_irq    (nios2_gen2_0_irq_irq)            //    sender.irq
	);

	altera_reset_controller #(
		.NUM_RESET_INPUTS          (2),
		.OUTPUT_RESET_SYNC_EDGES   ("deassert"),
		.SYNC_DEPTH                (2),
		.RESET_REQUEST_PRESENT     (1),
		.RESET_REQ_WAIT_TIME       (1),
		.MIN_RST_ASSERTION_TIME    (3),
		.RESET_REQ_EARLY_DSRT_TIME (1),
		.USE_RESET_REQUEST_IN0     (0),
		.USE_RESET_REQUEST_IN1     (0),
		.USE_RESET_REQUEST_IN2     (0),
		.USE_RESET_REQUEST_IN3     (0),
		.USE_RESET_REQUEST_IN4     (0),
		.USE_RESET_REQUEST_IN5     (0),
		.USE_RESET_REQUEST_IN6     (0),
		.USE_RESET_REQUEST_IN7     (0),
		.USE_RESET_REQUEST_IN8     (0),
		.USE_RESET_REQUEST_IN9     (0),
		.USE_RESET_REQUEST_IN10    (0),
		.USE_RESET_REQUEST_IN11    (0),
		.USE_RESET_REQUEST_IN12    (0),
		.USE_RESET_REQUEST_IN13    (0),
		.USE_RESET_REQUEST_IN14    (0),
		.USE_RESET_REQUEST_IN15    (0),
		.ADAPT_RESET_REQUEST       (0)
	) rst_controller (
		.reset_in0      (~reset_reset_n),                         // reset_in0.reset
		.reset_in1      (nios2_gen2_0_debug_reset_request_reset), // reset_in1.reset
		.clk            (clk_clk),                                //       clk.clk
		.reset_out      (rst_controller_reset_out_reset),         // reset_out.reset
		.reset_req      (rst_controller_reset_out_reset_req),     //          .reset_req
		.reset_req_in0  (1'b0),                                   // (terminated)
		.reset_req_in1  (1'b0),                                   // (terminated)
		.reset_in2      (1'b0),                                   // (terminated)
		.reset_req_in2  (1'b0),                                   // (terminated)
		.reset_in3      (1'b0),                                   // (terminated)
		.reset_req_in3  (1'b0),                                   // (terminated)
		.reset_in4      (1'b0),                                   // (terminated)
		.reset_req_in4  (1'b0),                                   // (terminated)
		.reset_in5      (1'b0),                                   // (terminated)
		.reset_req_in5  (1'b0),                                   // (terminated)
		.reset_in6      (1'b0),                                   // (terminated)
		.reset_req_in6  (1'b0),                                   // (terminated)
		.reset_in7      (1'b0),                                   // (terminated)
		.reset_req_in7  (1'b0),                                   // (terminated)
		.reset_in8      (1'b0),                                   // (terminated)
		.reset_req_in8  (1'b0),                                   // (terminated)
		.reset_in9      (1'b0),                                   // (terminated)
		.reset_req_in9  (1'b0),                                   // (terminated)
		.reset_in10     (1'b0),                                   // (terminated)
		.reset_req_in10 (1'b0),                                   // (terminated)
		.reset_in11     (1'b0),                                   // (terminated)
		.reset_req_in11 (1'b0),                                   // (terminated)
		.reset_in12     (1'b0),                                   // (terminated)
		.reset_req_in12 (1'b0),                                   // (terminated)
		.reset_in13     (1'b0),                                   // (terminated)
		.reset_req_in13 (1'b0),                                   // (terminated)
		.reset_in14     (1'b0),                                   // (terminated)
		.reset_req_in14 (1'b0),                                   // (terminated)
		.reset_in15     (1'b0),                                   // (terminated)
		.reset_req_in15 (1'b0)                                    // (terminated)
	);

endmodule

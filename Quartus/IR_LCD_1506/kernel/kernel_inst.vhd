	component kernel is
		port (
			clk_clk                              : in    std_logic                     := 'X';             -- clk
			ir_1506_conduit_end_0_export         : in    std_logic                     := 'X';             -- export
			lcd_1506_conduit_end_0_export_data   : inout std_logic_vector(7 downto 0)  := (others => 'X'); -- export_data
			lcd_1506_conduit_end_0_export_rw     : out   std_logic;                                        -- export_rw
			lcd_1506_conduit_end_0_export_en     : out   std_logic;                                        -- export_en
			lcd_1506_conduit_end_0_export_rs     : out   std_logic;                                        -- export_rs
			lcd_1506_conduit_end_0_export_blon   : out   std_logic;                                        -- export_blon
			lcd_1506_conduit_end_0_export_on     : out   std_logic;                                        -- export_on
			new_sdram_controller_wire_addr       : out   std_logic_vector(12 downto 0);                    -- addr
			new_sdram_controller_wire_ba         : out   std_logic_vector(1 downto 0);                     -- ba
			new_sdram_controller_wire_cas_n      : out   std_logic;                                        -- cas_n
			new_sdram_controller_wire_cke        : out   std_logic;                                        -- cke
			new_sdram_controller_wire_cs_n       : out   std_logic;                                        -- cs_n
			new_sdram_controller_wire_dq         : inout std_logic_vector(31 downto 0) := (others => 'X'); -- dq
			new_sdram_controller_wire_dqm        : out   std_logic_vector(3 downto 0);                     -- dqm
			new_sdram_controller_wire_ras_n      : out   std_logic;                                        -- ras_n
			new_sdram_controller_wire_we_n       : out   std_logic;                                        -- we_n
			pio_0_external_connection_export     : out   std_logic;                                        -- export
			pio_1_external_connection_export     : out   std_logic;                                        -- export
			pio_2_external_connection_export     : out   std_logic;                                        -- export
			pio_3_external_connection_export     : out   std_logic;                                        -- export
			pio_4_external_connection_export     : out   std_logic;                                        -- export
			pio_5_external_connection_export     : out   std_logic;                                        -- export
			pio_6_external_connection_export     : out   std_logic;                                        -- export
			pio_7_external_connection_export     : out   std_logic;                                        -- export
			reset_reset_n                        : in    std_logic                     := 'X';             -- reset_n
			user_gio_pwm_0_conduit_end_0_export  : out   std_logic;                                        -- export
			user_gio_pwm_10_conduit_end_0_export : out   std_logic;                                        -- export
			user_gio_pwm_11_conduit_end_0_export : out   std_logic;                                        -- export
			user_gio_pwm_12_conduit_end_0_export : out   std_logic;                                        -- export
			user_gio_pwm_13_conduit_end_0_export : out   std_logic;                                        -- export
			user_gio_pwm_14_conduit_end_0_export : out   std_logic;                                        -- export
			user_gio_pwm_15_conduit_end_0_export : out   std_logic;                                        -- export
			user_gio_pwm_16_conduit_end_0_export : out   std_logic;                                        -- export
			user_gio_pwm_17_conduit_end_0_export : out   std_logic;                                        -- export
			user_gio_pwm_1_conduit_end_0_export  : out   std_logic;                                        -- export
			user_gio_pwm_2_conduit_end_0_export  : out   std_logic;                                        -- export
			user_gio_pwm_3_conduit_end_0_export  : out   std_logic;                                        -- export
			user_gio_pwm_4_conduit_end_0_export  : out   std_logic;                                        -- export
			user_gio_pwm_5_conduit_end_0_export  : out   std_logic;                                        -- export
			user_gio_pwm_6_conduit_end_0_export  : out   std_logic;                                        -- export
			user_gio_pwm_7_conduit_end_0_export  : out   std_logic;                                        -- export
			user_gio_pwm_8_conduit_end_0_export  : out   std_logic;                                        -- export
			user_gio_pwm_9_conduit_end_0_export  : out   std_logic                                         -- export
		);
	end component kernel;

	u0 : component kernel
		port map (
			clk_clk                              => CONNECTED_TO_clk_clk,                              --                           clk.clk
			ir_1506_conduit_end_0_export         => CONNECTED_TO_ir_1506_conduit_end_0_export,         --         ir_1506_conduit_end_0.export
			lcd_1506_conduit_end_0_export_data   => CONNECTED_TO_lcd_1506_conduit_end_0_export_data,   --        lcd_1506_conduit_end_0.export_data
			lcd_1506_conduit_end_0_export_rw     => CONNECTED_TO_lcd_1506_conduit_end_0_export_rw,     --                              .export_rw
			lcd_1506_conduit_end_0_export_en     => CONNECTED_TO_lcd_1506_conduit_end_0_export_en,     --                              .export_en
			lcd_1506_conduit_end_0_export_rs     => CONNECTED_TO_lcd_1506_conduit_end_0_export_rs,     --                              .export_rs
			lcd_1506_conduit_end_0_export_blon   => CONNECTED_TO_lcd_1506_conduit_end_0_export_blon,   --                              .export_blon
			lcd_1506_conduit_end_0_export_on     => CONNECTED_TO_lcd_1506_conduit_end_0_export_on,     --                              .export_on
			new_sdram_controller_wire_addr       => CONNECTED_TO_new_sdram_controller_wire_addr,       --     new_sdram_controller_wire.addr
			new_sdram_controller_wire_ba         => CONNECTED_TO_new_sdram_controller_wire_ba,         --                              .ba
			new_sdram_controller_wire_cas_n      => CONNECTED_TO_new_sdram_controller_wire_cas_n,      --                              .cas_n
			new_sdram_controller_wire_cke        => CONNECTED_TO_new_sdram_controller_wire_cke,        --                              .cke
			new_sdram_controller_wire_cs_n       => CONNECTED_TO_new_sdram_controller_wire_cs_n,       --                              .cs_n
			new_sdram_controller_wire_dq         => CONNECTED_TO_new_sdram_controller_wire_dq,         --                              .dq
			new_sdram_controller_wire_dqm        => CONNECTED_TO_new_sdram_controller_wire_dqm,        --                              .dqm
			new_sdram_controller_wire_ras_n      => CONNECTED_TO_new_sdram_controller_wire_ras_n,      --                              .ras_n
			new_sdram_controller_wire_we_n       => CONNECTED_TO_new_sdram_controller_wire_we_n,       --                              .we_n
			pio_0_external_connection_export     => CONNECTED_TO_pio_0_external_connection_export,     --     pio_0_external_connection.export
			pio_1_external_connection_export     => CONNECTED_TO_pio_1_external_connection_export,     --     pio_1_external_connection.export
			pio_2_external_connection_export     => CONNECTED_TO_pio_2_external_connection_export,     --     pio_2_external_connection.export
			pio_3_external_connection_export     => CONNECTED_TO_pio_3_external_connection_export,     --     pio_3_external_connection.export
			pio_4_external_connection_export     => CONNECTED_TO_pio_4_external_connection_export,     --     pio_4_external_connection.export
			pio_5_external_connection_export     => CONNECTED_TO_pio_5_external_connection_export,     --     pio_5_external_connection.export
			pio_6_external_connection_export     => CONNECTED_TO_pio_6_external_connection_export,     --     pio_6_external_connection.export
			pio_7_external_connection_export     => CONNECTED_TO_pio_7_external_connection_export,     --     pio_7_external_connection.export
			reset_reset_n                        => CONNECTED_TO_reset_reset_n,                        --                         reset.reset_n
			user_gio_pwm_0_conduit_end_0_export  => CONNECTED_TO_user_gio_pwm_0_conduit_end_0_export,  --  user_gio_pwm_0_conduit_end_0.export
			user_gio_pwm_10_conduit_end_0_export => CONNECTED_TO_user_gio_pwm_10_conduit_end_0_export, -- user_gio_pwm_10_conduit_end_0.export
			user_gio_pwm_11_conduit_end_0_export => CONNECTED_TO_user_gio_pwm_11_conduit_end_0_export, -- user_gio_pwm_11_conduit_end_0.export
			user_gio_pwm_12_conduit_end_0_export => CONNECTED_TO_user_gio_pwm_12_conduit_end_0_export, -- user_gio_pwm_12_conduit_end_0.export
			user_gio_pwm_13_conduit_end_0_export => CONNECTED_TO_user_gio_pwm_13_conduit_end_0_export, -- user_gio_pwm_13_conduit_end_0.export
			user_gio_pwm_14_conduit_end_0_export => CONNECTED_TO_user_gio_pwm_14_conduit_end_0_export, -- user_gio_pwm_14_conduit_end_0.export
			user_gio_pwm_15_conduit_end_0_export => CONNECTED_TO_user_gio_pwm_15_conduit_end_0_export, -- user_gio_pwm_15_conduit_end_0.export
			user_gio_pwm_16_conduit_end_0_export => CONNECTED_TO_user_gio_pwm_16_conduit_end_0_export, -- user_gio_pwm_16_conduit_end_0.export
			user_gio_pwm_17_conduit_end_0_export => CONNECTED_TO_user_gio_pwm_17_conduit_end_0_export, -- user_gio_pwm_17_conduit_end_0.export
			user_gio_pwm_1_conduit_end_0_export  => CONNECTED_TO_user_gio_pwm_1_conduit_end_0_export,  --  user_gio_pwm_1_conduit_end_0.export
			user_gio_pwm_2_conduit_end_0_export  => CONNECTED_TO_user_gio_pwm_2_conduit_end_0_export,  --  user_gio_pwm_2_conduit_end_0.export
			user_gio_pwm_3_conduit_end_0_export  => CONNECTED_TO_user_gio_pwm_3_conduit_end_0_export,  --  user_gio_pwm_3_conduit_end_0.export
			user_gio_pwm_4_conduit_end_0_export  => CONNECTED_TO_user_gio_pwm_4_conduit_end_0_export,  --  user_gio_pwm_4_conduit_end_0.export
			user_gio_pwm_5_conduit_end_0_export  => CONNECTED_TO_user_gio_pwm_5_conduit_end_0_export,  --  user_gio_pwm_5_conduit_end_0.export
			user_gio_pwm_6_conduit_end_0_export  => CONNECTED_TO_user_gio_pwm_6_conduit_end_0_export,  --  user_gio_pwm_6_conduit_end_0.export
			user_gio_pwm_7_conduit_end_0_export  => CONNECTED_TO_user_gio_pwm_7_conduit_end_0_export,  --  user_gio_pwm_7_conduit_end_0.export
			user_gio_pwm_8_conduit_end_0_export  => CONNECTED_TO_user_gio_pwm_8_conduit_end_0_export,  --  user_gio_pwm_8_conduit_end_0.export
			user_gio_pwm_9_conduit_end_0_export  => CONNECTED_TO_user_gio_pwm_9_conduit_end_0_export   --  user_gio_pwm_9_conduit_end_0.export
		);


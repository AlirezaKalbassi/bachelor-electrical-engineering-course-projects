`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:49:17 01/20/2025
// Design Name:   project
// Module Name:   F:/Desktop/university/term 9/FPGA/project/project/project_t.v
// Project Name:  project
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: project
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module project_t;

	// Inputs
	reg rx;
	reg clk;
	reg rst;

	// Outputs
	wire [7:0] d;
	wire [2:0] s;

	// Instantiate the Unit Under Test (UUT)
	project uut (
		.rx(rx), 
		.clk(clk), 
		.rst(rst), 
		.d(d), 
		.s(s)
	);

	initial begin
		rx = 1;
		clk = 1;
		rst = 0;
	end
	
	initial #20 rst=1;
	initial forever #10 clk=!clk;
	
	initial #200 rx=0;
	initial #400 rx=0;
	initial #600 rx=1;
	initial #800 rx=0;
	initial #1000 rx=0;
	initial #1200 rx=1;
	initial #1400 rx=1;
	initial #1600 rx=0;
	initial #1800 rx=0;
	initial #2000 rx=1;
	
	initial #2200 rx=0;
	initial #2400 rx=0;
	initial #2600 rx=1;
	initial #2800 rx=0;
	initial #3000 rx=0;
	initial #3200 rx=0;
	initial #3400 rx=0;
	initial #3600 rx=1;
	initial #3800 rx=0;
	initial #4000 rx=1;
	
	initial #4200 rx=0;
	initial #4400 rx=1;
	initial #4600 rx=0;
	initial #4800 rx=0;
	initial #5000 rx=0;
	initial #5200 rx=0;
	initial #5400 rx=1;
	initial #5600 rx=1;
	initial #5800 rx=0;
	initial #6000 rx=1;
      
endmodule


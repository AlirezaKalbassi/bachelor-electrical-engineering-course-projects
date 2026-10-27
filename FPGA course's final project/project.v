`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:15:35 01/20/2025 
// Design Name: 
// Module Name:    project 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module project(
    input rx,
    input clk,
    input rst,
    output [7:0] d,
    output [5:0] s
    );
	 
	 reg [3:0] state;
	 wire [3:0] next_state;
	 reg [7:0] rm [0:2];
	 reg [7:0] ro [0:2];
	 reg [12:0] cnt;
	 reg [1:0] rn;
	 reg [7:0] d;
	 reg [5:0] s;
	 reg [1:0] i;
	 reg [9:0] m;
	 
	 parameter n = 5208;
	 parameter idl=0;
	 parameter startb=1;
	 parameter r0=2;
	 parameter r1=3;
	 parameter r2=4;
	 parameter r3=5;
	 parameter r4=6;
	 parameter r5=7;
	 parameter r6=8;
	 parameter r7=9;
	 parameter stopb=10;
	 ////////////////////////////////////////////////////////////////////
	 assign next_state = (state==idl && rx==1)? idl:
								(state==idl && rx==0)? startb:
								(state==startb && cnt<n)? startb:
								(state==startb && cnt==n)? r0:
								(state==r0 && cnt<n)? r0:
								(state==r0 && cnt==n)? r1:
								(state==r1 && cnt<n)? r1:
								(state==r1 && cnt==n)? r2:
								(state==r2 && cnt<n)? r2:
								(state==r2 && cnt==n)? r3:
								(state==r3 && cnt<n)? r3:
								(state==r3 && cnt==n)? r4:
								(state==r4 && cnt<n)? r4:
								(state==r4 && cnt==n)? r5:
								(state==r5 && cnt<n)? r5:
								(state==r5 && cnt==n)? r6:
								(state==r6 && cnt<n)? r6:
								(state==r6 && cnt==n)? r7:
								(state==r7 && cnt<n)? r7:
								(state==r7 && cnt==n)? stopb:
								(state==stopb && cnt<n)? stopb:idl;
								
	//////////////////////////////////////////////////////////////////////////							
								
	 always @ (posedge clk)
		if (rst==0)
			state=idl;
		else
			state=next_state;
	////////////////////////////////////////////////////////////////////////////
	 
	 always @ (posedge clk) 
		if (cnt==n/2)
			case (state)
				r0: rm[rn][0]=rx;
				r1: rm[rn][1]=rx;
				r2: rm[rn][2]=rx;
				r3: rm[rn][3]=rx;
				r4: rm[rn][4]=rx;
				r5: rm[rn][5]=rx;
				r6: rm[rn][6]=rx;
				r7: rm[rn][7]=rx;
			endcase
	/////////////////////////////////////////////////////////////////////////////
		
	 always @ (posedge clk)
		if(rst==0)
			begin
			cnt=0;
			rn=0;
			end
		else if (state==startb && cnt<n)
			cnt=cnt+1;
		else if (state==startb && cnt==n)
			cnt=0;
		else if (state==r0 && cnt<n)
			cnt=cnt+1;
		else if (state==r0 && cnt==n)
			cnt=0;
		else if (state==r1 && cnt<n)
			cnt=cnt+1;
		else if (state==r1 && cnt==n)
			cnt=0;
		else if (state==r2 && cnt<n)
			cnt=cnt+1;
		else if (state==r2 && cnt==n)
			cnt=0;
		else if (state==r3 && cnt<n)
			cnt=cnt+1;
		else if (state==r3 && cnt==n)
			cnt=0;
		else if (state==r4 && cnt<n)
			cnt=cnt+1;
		else if (state==r4 && cnt==n)
			cnt=0;
		else if (state==r5 && cnt<n)
			cnt=cnt+1;
		else if (state==r5 && cnt==n)
			cnt=0;
		else if (state==r6 && cnt<n)
			cnt=cnt+1;
		else if (state==r6 && cnt==n)
			cnt=0;
		else if (state==r7 && cnt<n)
			cnt=cnt+1;
		else if (state==r7 && cnt==n)
			cnt=0;
		else if (state==stopb && cnt<n)
			cnt=cnt+1;
		else if (state==stopb && cnt==n && rn<2)
			begin
			cnt=0;
			rn=rn+1;
			end
		else if (state==stopb && cnt==n && rn==2)
			begin 
			cnt=0;
			rn=0;
			ro[0]=rm[0];
			ro[1]=rm[1];
			ro[2]=rm[2];
			end
	///////////////////////////////////////////////////////////////////////////////

	 always @ (posedge clk)
		if (rst==0)
		begin
			i=1;
			m=0;
		end
		else if (m<1000)
			m=m+1;
		else if (i<2 && m==1000)	
			begin
			i=i+1;
			m=0;
			end
		else 
			begin
			i=0;
			m=0;
			end
	///////////////////////////////////////////////////////////////////////////////
	// 7_segment : r[0]=a	r[1]=b	r[2]=c	r[3]=d	r[4]=e	r[5]=f	r[6]=g	r[7]=db
	always @ (*)  
			case (ro[i])
				48: d<=8'b11000000;
				49: d<=8'b11111001;
				50: d<=8'b10100100;
				51: d<=8'b10110000;
				52: d<=8'b10011001;
				53: d<=8'b10010010;
				54: d<=8'b10000010;
				55: d<=8'b11111000;
				56: d<=8'b10000000;
				57: d<=8'b10010000;
				97: d<=8'b10100000;
				98: d<=8'b10000011;
				99: d<=8'b10100111;
				100: d<=8'b10100001;
				101: d<=8'b10000110;
				102: d<=8'b10001110;
				103: d<=8'b11000010;
				104: d<=8'b10001011;
				105: d<=8'b11101110;
				106: d<=8'b11110010;
				107: d<=8'b10001010;
				108: d<=8'b11000111;
				109: d<=8'b10101010;
				110: d<=8'b10101011;
				111: d<=8'b10100011;
				112: d<=8'b10001100;
				113: d<=8'b10011000;
				114: d<=8'b10101111;
				115: d<=8'b11010010;
				116: d<=8'b10000111;
				117: d<=8'b11100011;
				118: d<=8'b11010101;
				119: d<=8'b10010101;
				120: d<=8'b11101011;
				121: d<=8'b10010001;
				122: d<=8'b11100100;
				65: d<=8'b00100000;
				66: d<=8'b00000011;
				67: d<=8'b00100111;
				68: d<=8'b00100001;
				69: d<=8'b00000110;
				70: d<=8'b00001110;
				71: d<=8'b01000010;
				72: d<=8'b00001011;
				73: d<=8'b01101110;
				74: d<=8'b01110010;
				75: d<=8'b00001010;
				76: d<=8'b01000111;
				77: d<=8'b00101010;
				78: d<=8'b00101011;
				79: d<=8'b00100011;
				80: d<=8'b00001100;
				81: d<=8'b00011000;
				82: d<=8'b00101111;
				83: d<=8'b01010010;
				84: d<=8'b00000111;
				85: d<=8'b01100011;
				86: d<=8'b01010101;
				87: d<=8'b00010101;
				88: d<=8'b01101011;
				89: d<=8'b00010001;
				90: d<=8'b01100100;
				default d<=0;
				endcase
	
	 always @ (*)
		case (i)
			0: s=6'b111110;
			1: s=6'b111101;
			2: s=6'b111011;
			endcase
					

	 
	 
endmodule

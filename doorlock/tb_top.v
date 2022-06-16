`timescale 1ns/1ns

module tb_top();
    
    reg clk, rst, ps_start, ps_end;
    reg [3:0] ps_num;
    wire door_open, state_out;
    wire [7:0] w1, w2, w3, w4, w5, w6;
    wire out_clk;
    wire [1:0] state, seg_out;
    
    clk_dll u0(rst, clk, out_clk);
    state_machine u1(rst, out_clk, ps_start, ps_end, state);
    doorlock u2(state, ps_num, door_open, seg_out);
    seg7 u3(seg_out, w1, w2, w3, w4, w5, w6);
    
    initial
    begin
        rst      = 0;
        #32; rst = 1;
    end
    initial
    begin
        clk            = 0;
        forever #5 clk = !clk;
    end
    
endmodule

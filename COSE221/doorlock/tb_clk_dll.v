`timescale 1ns/1ns

module tb_clk();
    reg clk, rst;
    wire out_clk;
    
    clk_dll u0(rst,clk,out_clk);
    
    initial
    begin
        rst      = 0;
        #33; rst = 1;
    end
    
    initial
    begin
        clk            = 0;
        forever #5 clk = ~clk;
    end
    
endmodule

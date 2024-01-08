`timescale 1ns/1ns

module tb_sync_cnt ();
    reg rst, clk;
    wire [3:0] out0, out1, out2, out3;
    wire clk1, clk2, clk3;

    sync_cnt u0(rst, clk, out0, out1, out2, out3, clk1, clk2, clk3);

    initial begin
        rst = 0;
        #32; rst = 1;
    end

    initial begin
        clk = 0;
        forever begin
            #5 clk = !clk;
        end
    end
endmodule
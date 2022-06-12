module cnt2 (rst, clk, out, out_clk);
    input rst, clk;
    output [3:0] out;
    output out_clk;
    reg [3:0] out;
    reg [9:0] cnt_clk;
    reg out_clk;

    always@(posedge clk or negedge rst) begin
        if(!rst) begin
            cnt_clk <= 0;
            out_clk <= 0;
        end
        else begin  
            cnt_clk <= cnt_clk + 1;
            if(cnt_clk == 49) begin
                cnt_clk <= 0;
            end
            else if(cnt_clk == 0) begin
                out_clk <= !out_clk;
            end
        end
    end 

    always@(posedge out_clk or negedge rst) begin
        if(!rst) begin
            out <= 0;
        end
        else begin  
            out <= out + 1;
            if (out == 10) begin
                out <= 0;
            end
        end
    end 
endmodule

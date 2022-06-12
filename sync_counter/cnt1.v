module cnt1 (rst, clk, out, out_clk);
    input rst, clk;
    output [3:0] out;
    output out_clk;
    reg [3:0] out, tmp;
    reg [9:0] cnt_clk;
    reg out_clk;

    always@(posedge clk or negedge rst) begin
        if(!rst) begin
            cnt_clk <= 0;
            out_clk <= 0;
        end
        else begin  
            cnt_clk <= cnt_clk + 1;
            if(cnt_clk == 4) begin
                cnt_clk <= 0;
            end
            else if(cnt_clk == 0) begin
                out_clk <= !out_clk;
            end
        end
    end 

    always@(posedge out_clk or negedge rst) begin
        if (!rst) begin
            out <= 0;
            tmp <= 0;
        end
        else begin
            tmp <= tmp + 1;
            if (tmp == 16) begin
                tmp <= 0;
            end
            out <= tmp;
        end
    end 
endmodule

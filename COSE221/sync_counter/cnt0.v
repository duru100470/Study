module cnt0 (rst, clk, out);
    input rst, clk;
    output [3:0] out;
    reg [3:0] out, tmp;

    always @(posedge clk or negedge rst) begin
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
module cnt0 (rst, clk, out);
    input rst, clk;
    output [3:0] out;
    reg [3:0] out;

    always @(posedge clk or negedge rst) begin
        if (!rst) begin
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
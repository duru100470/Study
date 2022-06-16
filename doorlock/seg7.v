module seg7(in,
            w1,
            w2,
            w3,
            w4,
            w5,
            w6);
    input [1:0] in;
    output [6:0] w1, w2, w3, w4, w5, w6;
    
    reg [6:0] w1, w2, w3, w4, w5, w6;
    
    always @(in) begin
        case(in)
            2'b00:
            begin
                w1 <= 7'b0000000;
                w2 <= 7'b0000000;
                w3 <= 7'b0000000;
                w4 <= 7'b0000000;
                w5 <= 7'b0000000;
                w6 <= 7'b0000000;
            end
            2'b01:
            begin
                w1 <= 7'b0000000;
                w2 <= 7'b0000000;
                w3 <= 7'b1111110;
                w4 <= 7'b1100111;
                w5 <= 7'b1001111;
                w6 <= 7'b1110110;
            end
            2'b10:
            begin
                w1 <= 7'b1001110;
                w2 <= 7'b0001110;
                w3 <= 7'b1111110;
                w4 <= 7'b1011011;
                w5 <= 7'b1001111;
                w6 <= 7'b1111110;
            end
        endcase
    end
endmodule

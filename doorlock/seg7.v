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
                w1 <= 7'b0111111;
                w2 <= 7'b0111111;
                w3 <= 7'b0111111;
                w4 <= 7'b0111111;
                w5 <= 7'b0111111;
                w6 <= 7'b0111111;
            end
            2'b01:
            begin
                w1 <= 7'b1111111;
                w2 <= 7'b1111111;
                w3 <= 7'b1000000;
                w4 <= 7'b0001100;
                w5 <= 7'b0000110;
                w6 <= 7'b0101011;
            end
            2'b10:
            begin
                w1 <= 7'b1000110;
                w2 <= 7'b1000111;
                w3 <= 7'b1000000;
                w4 <= 7'b0010010;
                w5 <= 7'b0000110;
                w6 <= 7'b0100001;
            end
        endcase
    end
endmodule

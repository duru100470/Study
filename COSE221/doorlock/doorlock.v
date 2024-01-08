module doorlock(state,
                ps_num,
                door_open,
                seg_out);
    input [1:0] state;
    input [3:0] ps_num;
    output door_open;
    output [1:0] seg_out;
    
    reg door_open;
    reg [1:0] state_out, seg_out;
	 reg [3:0] pw;
    parameter PASSWORD = 4'b1101;
    
    always @(state) begin
        case(state)
            2'b00:
            begin
                door_open <= 0;
                seg_out   <= 2'b10;
            end
            2'b01:
            begin
                door_open <= 0;
                seg_out   <= 2'b00;
					 pw <= ps_num;
            end
            2'b10:
            begin
                if (pw == PASSWORD) begin
                    door_open <= 1;
                    seg_out   <= 2'b01;
                end
                else begin
                    door_open <= 0;
                    seg_out   <= 2'b10;
                end
            end
        endcase
    end
endmodule

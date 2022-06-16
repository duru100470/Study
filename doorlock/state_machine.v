module state_machine(rst,
                     clk,
                     ps_start,
                     ps_end,
                     state_out);
    input rst, clk, ps_start, ps_end;
    output [1:0] state_out;
    reg [1:0] state_out, next_state, state;
    reg [13:0] cnt_clk;
    parameter STATE_IDLE  = 2'b00;
    parameter STATE_START = 2'b01;
    parameter STATE_END   = 2'b10;
    
    always @(posedge clk or negedge rst) begin
        if (!rst) begin
            state <= STATE_IDLE;
            cnt_clk <= 0;
        end
        else begin
            state <= next_state;
            cnt_clk <= cnt_clk + 1;
            if (cnt_clk >= 4999 || next_state != STATE_END)
                cnt_clk <= 0;
        end
    end
    
    always @(state or ps_start or ps_end or posedge clk) begin
        case (state)
            STATE_IDLE: if (ps_start)
            next_state <= STATE_START;
            else
            next_state <= STATE_IDLE;
            STATE_START: if (ps_end)
            next_state <= STATE_END;
            else
            next_state <= STATE_START;
            STATE_END: if (cnt_clk == 5000)
            next_state <= STATE_IDLE;
            else
            next_state <= STATE_END;
        endcase
    end
    
    always @(state) begin
        case(state)
            STATE_IDLE: state_out  <= 2'b00;
            STATE_START: state_out <= 2'b01;
            STATE_END: state_out   <= 2'b10;
        endcase
    end
endmodule

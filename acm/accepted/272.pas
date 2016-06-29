program p272;
{
@JUDGE_ID:  20044WC 272 PASCAL "DaP/DyP"
}
var
	c : char;
	b : boolean;
begin
	b := true;
	while not eof do begin
		read(c);
		if c = '"' then begin
			if b then write('``') else write('''''');
			b := not b;
		end else begin
			write(c);
		end;
	end;
end.

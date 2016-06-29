program p494;
{
	@JUDGE_ID:  20044WC 494 PASCAL "DaP/DyP"
}
var
	state : byte;
	c : char;
	w : longint;
function alphabet(x : char) : boolean;
begin
	alphabet := false;
	if (x >= 'A') and (x <= 'Z') then alphabet := true;
	if (x >= 'a') and (x <= 'z') then alphabet := true;
end;

begin
	while not eof do begin
		state := 0;
		w := 0;
		while not eoln do begin
			read(c);
			if (state = 0) and (alphabet(c)) then begin
				inc(w);
				state := 1;
			end else if not alphabet(c) then begin
				state := 0;
			end;
		end;
		if not eof then writeln(w);
		readln;
	end;
end.

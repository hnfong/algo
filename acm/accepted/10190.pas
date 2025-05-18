program p10190;
{
	@JUDGE_ID: 20044WC 10190 PASCAL "DaP/DyP"
}
var
	i,j,k : longint;
	a, b : longint;
	w : array[1..100] of longint;
begin
	while not eof do begin
		readln(a,b);
		w[1] := a;
		i := 1;
		if (b <= 1) or (a <= 1) then begin
			writeln('Boring!');
			continue;
		end;
		while w[i] mod b = 0 do begin
			inc(i);
			w[i] := w[i-1] div b;
		end;
		if w[i] <> 1 then writeln('Boring!') else begin
			for j := 1 to i-1 do begin
				write(w[j],' ');
			end;
			writeln(w[i]);
		end;
	end;
end.

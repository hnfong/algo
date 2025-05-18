program p10327;
{
@JUDGE_ID:  20044WC 10327 PASCAL "Grey"
}
var
	i,j,k : longint;
	a : array [1..1000] of longint;
	n : longint;
	f : longint;

procedure d(x : integer); var i : longint; begin for i := 1 to x * 67000000 do; end;

begin
	f := 0;
	while not eof do begin
		readln(n);
		for i := 1 to n do begin
			read(a[i]);
		end;
		readln;
		inc(f);
		f := 0;
		for i := 1 to n do begin
			for j := i downto 2 do begin
				if a[j] < a[j-1] then begin
					k := a[j];
					a[j] := a[j-1];
					a[j-1] := k;
					inc(f);
				end;
			end;
		end;
		writeln('Minimum exchange operations : ', f);
	end;
end.


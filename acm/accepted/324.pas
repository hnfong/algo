program p324;
{
	@JUDGE_ID: 20044WC 324 PASCAL "HPA"
}
var
	i,j,k : longint;
	w : array[1..1000] of integer;
	v : array[1..366,0..9] of longint;
	n : longint;
begin
	{ preprocess }
		w[1] := 1;
		for n := 1 to 366 do begin
			for j := 1 to 1000 do begin
				w[j] := w[j] * n;
			end;
			k := 0;
			for j := 1 to 1000 do begin
				w[j] := w[j]+k;
				k := w[j] div 10;
				w[j] := w[j] mod 10;
			end;
			for i := 1000 downto 1 do if w[i] > 0 then begin
				k := i;
				break;
			end;
			for i := k downto 1 do begin
				inc(v[n,w[i]]);
			end;
			end;
	{ io }
	while not eof do begin
		readln(n);
		if n = 0 then break;
		writeln(n,'! --');
		for i := 0 to 4 do begin
			if i > 0 then write(' ');
		write('   (', i, ')', v[n,i]:5);
		end;
		writeln;
		for i := 5 to 9 do begin
			if i > 5 then write(' ');
		write('   (', i, ')', v[n,i]:5);
		end;
		writeln;
	end;
end.


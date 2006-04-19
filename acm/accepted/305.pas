program p305;
{
	@JUDGE_ID: 20044WC 305 PASCAL "Simulation"
}
var
	i,j,k,m,n,l : longint;
	q : boolean;
	a : array[0..30] of longint;
	ans : array[1..13] of longint;
begin
	for k := 1 to 13 do begin
	for m := 1 to 3000000 do begin
		n := k * 2;
		for i := 0 to n-1 do a[i] := i;
		l := 0;
		q := true;
		while n > k do begin
			l := ((m-1+l) mod n);
			if l < k then begin q := false; break; end;
			for i := l to n - 1 do a[i] := a[i+1];
			dec(n);
		end;
		if q then begin ans[k] := m ; break; end;
	end;
	end;

	while not eof do begin
		readln(k);
		if k = 0 then break;
		writeln(ans[k]);
	end;
end.


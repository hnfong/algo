program bsort;
var
	i,j,k,n : longint;
	a : array[1..8] of longint;
begin
	n := 8;
	for i := 1 to n do readln(a[i]);
	for i := n downto 1 do begin
		for j := i-1 downto 1 do begin
			if a[j] < a[j+1] then begin
				for k := 1 to n do begin
					write(a[k], ' ');
				end;writeln;
				k := a[j];
				a[j] := a[j+1];
				a[j+1] := k;
			end;
		end;
	end;
end.

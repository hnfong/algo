program sort3;
var
cs : array[0..3] of integer;
d : array[1..10000] of shortint;
off : array[1..3,1..3] of longint; { orig, should be }
i,j,k,n : longint;
begin
	readln(n);
	for i := 1 to n do begin
		readln(d[i]);
		inc(cs[d[i]]);
	end;
	for i := 1 to 3 do writeln(cs[i]);
	for j := 1 to 3 do begin
		for i := 1 to cs[j] do begin
			inc(off[j, d[i]]);
		end;
	end;
	
	for i := 1 to 3 do begin
		for j := 1 to 3 do begin
			if i = j then break;
			while off[i,j] > 0 do begin
				for k := cs[i-1] to cs[i] do begin
					
				end;
			end;
		end;
	end;
end.


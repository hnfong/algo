program lamps;
var
	i,j,k : longint;
	n,m : longint;
	w : array[1..1000000] of boolean;
	w1 : boolean;
begin
	randomize;
	readln(n,m);
	for i := 1 to n do begin
		readln(k);
		if k = 1 then w[i] := true else w[i] := false;
	end;
		for j := 1 to n do begin
			if w[j] then write('#') else write('.');
		end;writeln;
	
	for i := 1 to m do begin
		w1 := w[1];
		for j := 1 to n-1 do begin
			if w[j+1] then begin
				w[j] := not w[j];
			end;
		end;
		if w1 then w[n] := not w[n];
		
		for j := 1 to n do begin
			if w[j] then write('#') else write('.');
		end;writeln(' ', i+1);
	end;
	
	for j := 1 to n do begin
		if w[j] then write('#') else write('.');
	end;writeln;
end.

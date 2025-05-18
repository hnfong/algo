var
	i,j,k : longint;
	n  : Longint;
	w : array[1..750,1..3] of longint;
	a : array[1..750] of boolean;
	last : longint;
	b : array[1..750] of longint;
begin
	readln(n);
	for i := 1 to n do begin
		readln(w[i,1], w[i,2]);
		w[i,3] := i;
		a[i] := false;
	end;

	for i := 1 to n do begin
		for j := i downto 2 do begin
			if (w[j,1] < w[j-1,1]) then begin
				k := w[j,1];
				w[j,1] := w[j-1,1];
				w[j-1,1] := k;

				k := w[j,2];
				w[j,2] := w[j-1,2];
				w[j-1,2] := k;
				
				k := w[j,3];
				w[j,3] := w[j-1,3];
				w[j-1,3] := k;
			end;
		end;
	end;
	for i := 1 to n do begin
		for j := i downto 2 do begin
			if (w[j,2] < w[j-1,2]) then begin
				k := w[j,1];
				w[j,1] := w[j-1,1];
				w[j-1,1] := k;

				k := w[j,2];
				w[j,2] := w[j-1,2];
				w[j-1,2] := k;
				
				k := w[j,3];
				w[j,3] := w[j-1,3];
				w[j-1,3] := k;
			end;
		end;
	end;

	a[1] := true;
	last := w[1,2];
	
	for i := 2 to n do begin
		if (w[i,1] >= last) then begin
			a[i] := true;
			last := w[i,2];
		end;
	end;

	k := 0;

	for i:= 1 to n do begin
		if (a[i]) then inc(k);
	end;
	writeln(k);

	k := 0;

	for i := 1 to n do begin
		if (a[i]) then begin
			inc(k);
			b[k] := w[i, 3];
		end;
	end;

	for i := 1 to k do begin
		for j := i downto 2 do begin
			if (b[j] < b[j-1]) then begin
				n := b[j];
				b[j] := b[j-1];
				b[j-1 ] := n;
			end;
		end;
	end;

	for i := 1 to k do writeln(b[i]);
end.


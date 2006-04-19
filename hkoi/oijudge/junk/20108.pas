program p20108;
var
	i,j,k,t,max,n : longint;
	w : array[0..400,0..400] of longint;
begin
	readln(n);
	if n = 0 then begin
		writeln(0);
		exit;
	end;
	for i := 1 to n do begin
		for j := 1 to n do begin
			read(w[i,j]);
		end;
	end;

	for i := 1 to n do begin
		for j := 2 to n do begin
			w[i,j] := w[i,j] + w[i,j-1];
		end;
	end;
	max := 1 shl 31;
	for k := 1 to n do begin { k = the column count }
		for j := k to n do begin
			t := 0;
			for i := 1 to n do begin
				if t <= 0 then begin
					t := w[i,j]-w[i,j-k];
				end else begin
					t := t + w[i,j]-w[i,j-k];
				end;
				if t > max then max := t;
			end;
		end;
	end;
	writeln(max);
end.


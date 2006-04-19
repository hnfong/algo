program longestpath;
var
	w : array[1..26,1..26] of integer;
	i,j,k : longint;
begin
	for i := 1 to 26 do begin
		for j := 1 to 26 do begin
			w[i,j] := 30000;
		end;
	end;
	w[1,2]:=-1;
	w[2,3]:=-1;
	w[3,1]:=-1;
	w[1,4]:=-1;
	w[4,5]:=-1;
	w[5,1]:=-1;
	w[1,6]:=-1;
	for k := 1 to 6 do begin
		for i := 1 to 6 do begin
			for j := 1 to 6 do begin
				if w[i,k]+w[k,j] < w[i,j] then begin
					w[i,j] := w[i,k]+w[k,j];
					writeln(i, ' ', k , ' ', j, ' ', w[i,j]);
				end;
			end;
		end;
	end;

	writeln(w[1,1]);
end.

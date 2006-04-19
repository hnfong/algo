program p10443;
const
	hc : array[1..4, 1..2] of integer = (
	(1,0),
	(0,1),
	(-1,0),
	(0,-1)
	);

	win : array['P'..'S'] of char = ( 'R', ' ', 'S', 'P');
type
	maptype =  array[0..101,0..101] of char;
var
	w : maptype;
	v : maptype;
	t,i,j,k,r,c,n : longint;
	nc,ni : longint;

procedure dump;
var
	i,j,k : longint;
begin
	writeln('start of dump');
	for i := 1 to r do begin
		for j := 1 to c do begin
			write(w[i,j]);
		end;
		writeln;
	end;
	writeln;
	for i := 1 to r do begin
		for j := 1 to c do begin
			write(v[i,j]);
		end;
		writeln;
	end;
	writeln('end of dump');
end;

procedure evaluate(var w,v : maptype);
var
	i,j,k : longint;
begin
			for i := 1 to r do begin
				for j := 1 to c do begin
					for k := 1 to 4 do begin
	if (win[w[i,j]] = w[i+hc[k,1],j+hc[k,2]]) then begin
		v[i+hc[k,1],j+hc[k,2]] := w[i,j];
	end else begin
		v[i+hc[k,1],j+hc[k,2]] := w[i+hc[k,1],j+hc[k,2]];
	end;
					end;
				end;
			end;
end;

begin
	readln(nc);
	for ni := 1 to nc do begin
		readln(r,c,n);
		for i := 1 to r do begin
			for j := 1 to c do begin
				read(w[i,j]);
			end;
			readln;
		end;
		
		for t := 1 to n do begin
			if t mod 2 = 1 then evaluate(w,v);
			if t mod 2 = 0 then evaluate(v,w);
			dump;
		end;

	end;
end.

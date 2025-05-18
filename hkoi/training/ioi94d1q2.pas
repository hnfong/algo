program castle;
const	a : array [1..4] of integer = (8,4,2,1);
	dir : array[1..4,1..2] of shortint = ((1,0), (0,1), (-1,0), (0,-1));
type	coord = record
		r,c : shortint;
	end;
var
	i,j,k : longint;
	q : array[1..2500] of coord;
	qs : integer;
	qe : integer;
	map : array[0..101,0..101] of shortint;
	h,w : integer;
	t : Longint;
	fil : array[0..101,0..101] of shortint;
	co : coord;
	rooms : integer;
	maxsize : integer;
	ars : array[1..2500] of integer;

procedure pushq(r,c : shortint);
begin
	if (r = 0) or (c = 0) then exit;
	if (r > h) or (c > w) then exit;
	if (fil[r,c] > 0) then exit;
	fil [r,c] := 1;
	inc(qe);
	q[qe].r := r;
	q[qe].c := c;
end;

function popq : coord;
begin
	inc(qs);
	popq.r := q[qs].r;
	popq.c := q[qs].c;
end;

begin
	rooms := 0;
	qs := 0;
	qe := 0;
	fillchar(map,sizeof(map),0);
	fillchar(q,sizeof(q),0);
	fillchar(fil,sizeof(fil),0);
	readln(h);
	readln(w);
	for i := 1 to h do begin
		for j := 1 to w do begin
			read(map[i,j]);
		end;
		readln;
	end;

	for j := 1 to h do begin
	for k := 1 to w do begin
		qs := 0;
		qe := 0;
		fillchar(q,sizeof(q),0);
		pushq(j,k);
		while (qs <> qe) do begin
			co := popq;
			for i := 1 to 4 do begin
				t := map[co.r,co.c];
				if t >= a[i] then begin
					map[co.r,co.c] := t - a[i];
				end else begin
					writeln(co.r,' ',co.c,' ', i, ' ', co.r + dir[i,1], ' ', co.c+ dir[i,2],' ',t);
					pushq(co.r + dir[i,1], co.c+ dir[i,2]);
				end;
			end;
		end;
		if (qe > 0) then begin inc(rooms); ars[rooms] := qe end;
		if (qe > maxsize) then maxsize := qe;
	end;
	end;
	writeln(rooms);
	writeln(maxsize);
end.


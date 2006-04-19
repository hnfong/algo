program q4;
type
	r = record
		x,y : longint;
		bt : longint;
	end;
var
	i,j,k : longint;
	n,m : longint;
	map : array[0..31, 0..31] of char;
	v : array[0..31,0..31] of byte;
	q : array[1..1000] of r;
	qh, qt : longint;
	t : r;
	steps : longint;
	
procedure dump;begin
	for i := 1 to n do begin
		for j := 1 to m do begin
			write(v[j,i]);
		end;writeln;
	end;writeln;
end;

procedure enq (x,y,z : longint);
begin
	if (map[y,x] = '1') or (v[x,y] > 0) then exit;
	v[x,y] := 1;
	inc(qt);
	q[qt].x := x;
	q[qt].y := y;
	q[qt].bt := z;
end;

function deq : r;
begin
	inc(qh);
	deq.x := q[qh].x;
	deq.y := q[qh].y;
	deq.bt := q[qh].bt;
end;
procedure backtrack(x : longint);
begin
	if x = 0 then begin writeln(steps-1); exit; end;
	inc(steps);
	backtrack(q[x].bt);
	write('(', q[x].y, ',', q[x].x, ')');
end;

begin
	readln(n,m);
	fillchar(map,sizeof(map),'1');
	fillchar(v,sizeof(v),0);
	steps := 0;
	
	for i := 1 to n do begin
		for j := 1 to m do begin
			read(map[i,j]);
		end;
		readln;
	end;
	enq(1,1,0);
	while qh < qt do begin
		t := deq;
		if (t.x = m) and (t.y = n) then break;
		enq(t.x+1, t.y, qh);
		enq(t.x-1, t.y, qh);
		enq(t.x, t.y+1, qh);
		enq(t.x, t.y-1, qh);
		if (map[t.y, t.x] >= 'A') and (map[t.y, t.x] <= 'Z') then begin
			for i := 1 to n do begin
				for j := 1 to m do begin
					if map[i,j] = map[t.y, t.x] then enq(j,i, qh);
				end;
			end;
		end;
	end;
	backtrack(qh);
	writeln;
end.

program p10004;
{
@JUDGE_ID: 20044WC 10004 PASCAL "BFS"
}
label nexttest;
var
	i,j,k,n,v : integer;
	w : array[0..199,0..199] of boolean;
	q : array[0..199] of integer;
	c : array[0..199] of integer;  { 0 = nocolor, 1 = col1, 2=col2 }
	h,t : integer;
	a,b : integer;
	d : integer;
function flip(col:integer):integer;
begin
	flip := 0;
	if col=1 then flip:=2;
	if col=2 then flip:=1;
end;
procedure enq(x,col:integer);
begin
	if c[x] > 0 then exit;
	c[x] := col;
	inc(h);
	q[h] := x;
end;
function deq : integer;
begin
	inc(t);
	deq := q[t];
end;

begin
	while true do begin
		fillchar(w,sizeof(w),0);
		fillchar(q,sizeof(q),0);
		fillchar(c,sizeof(c),0);
		readln(n);
		if n = 0 then break;
		readln(v);
		for i := 1 to v do begin
			readln(a,b);
			w[a,b] := true;
			w[b,a] := true;
		end;
		enq(0,1);
		while h <> t do begin
			d := deq;
			for i := 0 to n-1 do begin
				if w[d,i] then begin
					if (c[i] = c[d]) then begin
						writeln('NOT BICOLORABLE.');
						goto nexttest;
					end;
					enq(i,flip(c[d]));
				end;
			end;
		end;
		writeln('BICOLORABLE.');
		nexttest:
	end;
end.

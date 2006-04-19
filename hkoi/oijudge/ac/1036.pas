program p1036;
const	
	sizen = 5000;
var
	i,j,k,n,t : longint;
	w : array[1..sizen*2] of longint;
	xpos : array[1..sizen] of longint;
	rmap : array[1..sizen] of longint;
	limit : longint;

procedure outdump;
var i : longint;
begin
	for i := 1 to n do begin
		w[xpos[i]] := i;
		w[xpos[i]+i+1] := i;
	end;
	for i := 1 to 2*n-1 do begin
		write(w[i], ' ');
	end;writeln(w[2*n]);
end;

procedure genrmap;
var a,b,t : longint;
begin
	a := random(n)+1;
	b := random(n)+1;
	t := rmap[a];
	rmap[a] := rmap[b];
	rmap[b] := t;
end;

function putx(x,l : longint; force:boolean) : boolean;
begin
	putx := false;
	if (w[l] > 0) and (force = false) then exit;
	xpos[x] := l;
	inc(w[l]);
	inc(w[l+x+1]);
	putx := true;
end;

function checkfinished : boolean;
var i : longint;
begin
	checkfinished := false;
	for i := 1 to 2*n do begin
		if w[i] = 0 then exit;
	end;
	checkfinished := true;
end;

function noconflictsearch(x:longint):longint;
var i : longint;
begin
	for i := 1 to 2*n-x-1 do begin
		if (w[i] = 0) and (w[i+x+1] = 0) then begin
			noconflictsearch := i;
			exit;
		end;
	end;
	noconflictsearch := 0;
end;
function oneconflictsearch(x : longint) : longint;
var
	i : longint;
	r : longint;
begin
	for i := 1 to 2*n do begin
		if w[i] = 0 then begin
			if (i <= 2*n-x-1) then r := i;
			if (i > 2*n-x-1) and (i-x-1 > 0) then r := i-x-1;
			oneconflictsearch := r;
			if r > 0 then exit;
		end;
	end;
	oneconflictsearch := 0;
end;
procedure delx(x:longint);
begin
	dec(w[xpos[x]]);
	dec(w[xpos[x]+x+1]);
end;

procedure movex(x,l : longint);
begin
	delx(x);
	putx(x, l, true);
end;
{bg}
begin
	{ initialize global variables }
	randomize;
	readln(n);
	limit := trunc( n * (ln(n)+1) ) ;
	for i := 1 to n do begin rmap[i] := i; end;
	for i := 1 to n do genrmap;
	while true do begin
		{ initialize a random thing }
		fillchar(w,sizeof(w),0);
		fillchar(xpos,sizeof(xpos),0);
		for j := n downto 1 do begin
			i := rmap[j];
			while not putx(i,random(2*n-i-1)+1,false) do;
		end;
		
		{ local search }
		k := 0;
		limit := limit * 2;
		while k < limit do begin
			genrmap;
			for j := 1 to n do begin
				i := rmap[j];
				if (w[ xpos[i]] > 1) and (w[ xpos[i]+i+1] > 1) then begin
					{ cutting cost by two. i.e. moving double conflicts to no conflicts }
					t := noconflictsearch(i);
					if t > 0 then begin movex(i, t); continue; end;
					
					{ cutting cost by one, by moving a double conflict to a single conflict }
					t := oneconflictsearch(i);
					if t > 0 then begin movex(i, t); continue; end;
				end;
			end;
			for j := 1 to n do begin
				i := rmap[j];
				if (w[ xpos[i]] > 1) or (w[ xpos[i]+i+1 ] > 1) then begin
					{ cutting cost by one, i.e. moving a single conflict to no conflict }
					t := noconflictsearch(i);
					if t > 0 then begin movex(i, t); continue; end;
			
					{ moving things around, hoping to get more things done...... }
					t := oneconflictsearch(i);
					if t > 0 then begin movex(i, t); continue; end;
				end;
			end;
			inc(k);
			if k mod trunc(sqrt(n)) = 0 then if checkfinished then break;
		end;
		if checkfinished then break;
	end;
	outdump;
end.


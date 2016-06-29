program p150;
{
@JUDGE_ID:  20044WC 150 PASCAL "DaP/DyP"
}
const
	mshc : array[1..12] of string[3] = ('Jan','Feb','Mar','Apr','May','Jun','Jul','Aug','Sep','Oct','Nov','Dec');
	wshc : array[0..6] of string[3]  = ('Sun','Mon','Tue','Wed','Thu','Fri','Sat');
	mshc2 : array[1..12] of string = ('January','February','March','Aprial','May','June','July','August','September','October','November','December');
	wshc2 : array[0..6] of string  = ('Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday');
	mdhc : array[1..12] of integer   = (31,28,31,30,31,30,31,31,30,31,30,31);
	oldhash : array[0..6] of integer = (1,2,3,4,5,6,0);
	newhash : array[0..6] of integer = (5,6,0,1,2,3,4);
procedure fsck;
begin
	while true do;
end;
function zeroone(b:boolean):longint; begin if b then zeroone := 1 else zeroone := 0; end;

function oldleap(y:longint):boolean;
begin
	oldleap := false;
	if ((y mod 4) = 0) then oldleap := true;
end;

function newleap(y:longint):boolean;
begin
	newleap := false;
	if ((y mod 4) = 0) and (((y mod 100) > 0) or ((y mod 400) = 0)) then newleap := true;
end;

{ new Friday 15 October 1582 }


{ retunrs 0..6 }
function olddow(d,m,y:longint) : byte ;
var
	z : longint;
	i,j,k: longint;
begin
	{ old Thursday 4 October 1582 }
	{ -> old Tuesday 1 Jan 1583 }
	{ z = days starting from 1 Jan 1583 ( including 1 Jan 1583 ) }
	z := 0;
	{ add up the years from 1583 }
	for i := 1583 to y-1 do begin
		if oldleap(i) then begin
			inc(z);  { leap years have one more day }
		end;
		inc(z, 365);
	end;
	
	{ add up the months }
	for i := 1 to m-1 do begin
		inc(z, mdhc[i]);
	end;
	if (m > 2) and oldleap(y) then inc(z);
	
	{ add up the days }
	inc(z, d);
	olddow := oldhash[z mod 7];
end;

{ retunrs 0..6 }
function newdow(d,m,y:longint) : byte ;
var
	z : longint;
	i,j,k: longint;
begin
	z := 0;
	{ add up the years from 1583 }
	for i := 1583 to y-1 do begin
		if newleap(i) then begin
			inc(z);  { leap years have one more day }
		end;
		inc(z, 365);
	end;
	
	{ add up the months }
	for i := 1 to m-1 do begin
		inc(z, mdhc[i]);
	end;
	if (m > 2) and newleap(y) then inc(z);
	
	{ add up the days }
	inc(z, d);
	newdow := newhash[z mod 7];
end;

var
	i,j,k : longint;
	w,d,m,y : longint;
	s : string[3];
	c : char;
	z : longint;
begin
	for y := 1600 to 2099 do begin
		for m := 1 to 12 do begin
			for d := 1 to mdhc[m] do begin
				writeln(wshc2[olddow(d,m,y)],' ',d,' ',mshc2[m], ' ',y);
			end;
		end;
	end;
end.


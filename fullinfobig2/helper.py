#!/usr/bin/python

def gen(cardsetstr):
    cardset = cardsetstr.split(" ")
    cond = " && ".join(["aa.indexOf('%s') != -1" % card for card in cardset])
    print 'if (' + cond + ') { r.push("' + cardsetstr + '"); }'

gen("H3 D4 H5 D6 C7")
gen("H3 D4 H5 D6 H7")
gen("H3 D4 H5 S6 C7")
gen("H3 D4 H5 S6 H7")

gen("H3 D4 S5 D6 C7")
gen("H3 D4 S5 D6 H7")
gen("H3 D4 S5 S6 C7")
gen("H3 D4 S5 S6 H7")

gen("H3 S4 H5 D6 C7")
gen("H3 S4 H5 D6 H7")
gen("H3 S4 H5 S6 C7")
gen("H3 S4 H5 S6 H7")

gen("H3 S4 S5 D6 C7")
gen("H3 S4 S5 D6 H7")
gen("H3 S4 S5 S6 C7")
gen("H3 S4 S5 S6 H7")

gen("S4 S5 S6 SQ SK")
gen("D4 D6 D9 DK D2")

gen("D4 S4 CQ HQ SQ")
gen("H5 S5 CQ HQ SQ")
gen("D6 S6 CQ HQ SQ")
gen("C7 H7 CQ HQ SQ")
gen("D9 C9 CQ HQ SQ")

gen("D4 S4 DK CK SK")
gen("H5 S5 DK CK SK")
gen("D6 S6 DK CK SK")
gen("C7 H7 DK CK SK")
gen("D9 C9 DK CK SK")

gen("CQ HQ SQ DK CK")
gen("CQ HQ SQ DK SK")
gen("CQ HQ SQ CK SK")

gen("CQ HQ DK CK SK")
gen("CQ SQ DK CK SK")
gen("HQ SQ DK CK SK")

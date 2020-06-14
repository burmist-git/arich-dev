#!/usr/bin/env python
# -*- coding: utf-8 -*-
from optparse import Option, OptionValueError, OptionParser

parser = OptionParser()
parser.add_option('-c', '--class', dest='whatclass', default='none', help="")
parser.add_option('-x', '--i-e', dest='importexport', default='export', help="")
parser.add_option('-t', '--test', dest='hvtest', default='no', help="")
(options, args) = parser.parse_args()
ie = options.importexport
ieClass = options.whatclass
hvtest = options.hvtest

import argparse

parser = argparse.ArgumentParser()
parser.add_argument("-o","--old", help="old have been replaced",required=True,type=str)
parser.add_argument("-n","--new", help="to be replaced",required=True,type=str)
parser.add_argument("-s","--string",help="which string to be altered",required=True,type=str)

args = parser.parse_args
def main():
    
    # print(f"argv: {parser.parse_args().old}")
    # print(f"argv: {parser.parse_args().new}")
    # print(f"argv: {parser.parse_args().string}")
    # old = parser.parse_args().old
    # new = parser.parse_args().new
    # ostring = parser.parse_args().string
    # nstring = ostring.replace(old,new)
    # print(nstring)
    
    
    print("\n"+parser.parse_args().string.replace(parser.parse_args().old,parser.parse_args().new)+"\n")




if __name__=="__main__":
    main()
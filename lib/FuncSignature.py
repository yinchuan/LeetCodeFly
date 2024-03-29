class FuncSignature:
    def __init__(self, name: str, return_type: str, parameter: [(str, str)]):
        self.name = name
        self.return_type = return_type
        self.parameter = parameter  # (type, name)

    def gen_parameter_declaration(self) -> str:
        # result example: int a; string c;
        if not self.parameter[0][0]:
            print("empty function parameter")
            return ""
        return ";\n".join(["%s %s" % (p[0].replace('&', ''), p[1]) for p in self.parameter])

    def gen_parameter_init(self) -> str:
        if not self.parameter[0][0]:
            print("empty function parameter")
            return ""
        return "=;\n".join([p[1] for p in self.parameter])

    def gen_parameter_pass_in(self) -> str:
        if not self.parameter[0][0]:
            print("empty function parameter")
            return ""
        return ", ".join([p[1] for p in self.parameter])

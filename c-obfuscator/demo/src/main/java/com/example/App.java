package com.example;

import java.io.IOException;

import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;

import com.example.c.*;
import com.example.c.CParser.CompilationUnitContext;

/**
 * Hello world!
 */
public final class App {
    private App() {
    }


    /**
     * Says hello to the world.
     * 
     * @param args The arguments of the program.
     * @throws IOException
     */
    public static void main(String[] args) throws IOException {
        if (args.length < 2) {
            System.out.println("Program <mutation> <file>");
        }
        CharStream stream = CharStreams.fromFileName(args[0]);
        CLexer l = new CLexer(stream);
        l.setTokenFactory(new CommonTokenFactory());
        CParser p = new CParser(new CommonTokenStream(l));

        CompilationUnitContext ctx = p.compilationUnit();

        ParseTreeVisitor<String> visitor = null;
        if (args[1].equals("syntax")) {
            visitor = new Obfuscator();
        } else if (args[1].equals("semantics")) {
            visitor = new Mutator();
        }
        else{
            System.out.printf("Incorrect argument %s%n",args[1]);
            return;
        }
        System.out.println("#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <math.h>");
        System.out.println(visitor.visit(ctx));

    }
}

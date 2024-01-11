package com.example;

import org.junit.jupiter.api.Test;

import com.example.c.CLexer;
import com.example.c.CParser;
import com.example.c.CParser.CompilationUnitContext;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTreeWalker;

/**
 * Unit test for simple App.
 */
class AppTest {
    /**
     * Rigorous Test.
     */
    //@Test
    void testMangler() {
String s ="""
int main(){

}
void f(int x)
{
    int y = 2;
    int z = x;
    main(2);
}
""";

        CharStream stream = CharStreams.fromString(s);
        CLexer l = new CLexer(stream);
        CParser p = new CParser(new CommonTokenStream(l));

        CompilationUnitContext ctx = p.compilationUnit();

        ParseTreeWalker walker = new ParseTreeWalker();
        Mangler mangler = new Mangler();
        walker.walk(mangler,ctx);
        // System.out.println("Allowed");
        // mangler.identifiers.forEach(System.out::println);
        // System.out.println("Forbidden");
        // mangler.forbiddenSet.forEach(System.out::println);

        System.out.println("Mapping");
        mangler.obfuscation.forEach((k,v) -> System.out.printf("%s -> %s%n",k,v) );

        System.out.println("New text");
        l.reset();
        l.getAllTokens().forEach( x -> System.out.print(mangler.obfuscation.getOrDefault(x.getText(), x.getText())));
        
    }

    //@Test
    void testObfuscator() {
        String s ="""
        int main(){
        
        }
        void f(int x)
        {
            int z = x;
            int y = 2;
            for(;i<100;i++)
            {
                
            }
            while(1){
                z++;
            }
            do{
                y++;

            }while(2);
            main(2);
        }
        """;
        
                CharStream stream = CharStreams.fromString(s);
                CLexer l = new CLexer(stream);
                CParser p = new CParser(new CommonTokenStream(l));
        
                CompilationUnitContext ctx = p.compilationUnit();
        
                Obfuscator obfuscator = new Obfuscator();
                // System.out.println("Allowed");
                // mangler.identifiers.forEach(System.out::println);
                // System.out.println("Forbidden");
                // mangler.forbiddenSet.forEach(System.out::println);
        
                System.out.println("Mapping");
                System.out.println(obfuscator.visit(ctx));
            }
 
            

    @Test
    void testMutator() {
        String s ="""
/*
        int main(){
        
        }
        void f(int x)
        {
            int z = x;
            int y = 2;
            for(;i<100;i++)
            {
                
            }
            while(1){
                z++;
            }
            do{
                y++;

            }while(2);
            main(2);
        }
*/
struct index {
    int x;
    int y;
  };
  struct interval {
    struct index left;
    struct index right;
  };
  struct interval pt;
        int main(){
            float a;
            a.b;
            float b;
            float area;
             scanf(\"%f %f\",&a, &b);
             area=.5*a*b;
             if (area>0)
              printf(\"The area of (%.4f,%.4f),(%.4f,0) and (0,%.4f) is %.4f.\",a,b,a,b,area);
              else
            printf(\"The area of (%.4f,%.4f),(%.4f,0) and (0,%.4f) is %.4f.\",a,b,a,b,-area);
            
            
                return 0;
            }

        """;
        
                CharStream stream = CharStreams.fromString(s);
                CLexer l = new CLexer(stream);
                CParser p = new CParser(new CommonTokenStream(l));
        
                CompilationUnitContext ctx = p.compilationUnit();
        
                Mutator mutator = new Mutator();
                // System.out.println("Allowed");
                // mangler.identifiers.forEach(System.out::println);
                // System.out.println("Forbidden");
                // mangler.forbiddenSet.forEach(System.out::println);
        
                //System.out.println("Mapping");
                System.out.println(mutator.visit(ctx));
                System.out.printf("Did I mutate %b?%n",mutator.hasBroken);
            }
 
}

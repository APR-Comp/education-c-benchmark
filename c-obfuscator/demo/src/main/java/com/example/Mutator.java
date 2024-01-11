package com.example;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Random;
import java.util.Set;

import org.antlr.v4.runtime.CommonToken;
import org.antlr.v4.runtime.tree.ErrorNode;
import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.TerminalNode;
import org.antlr.v4.runtime.tree.TerminalNodeImpl;

import com.example.c.CBaseVisitor;
import com.example.c.CLexer;
import com.example.c.CParser.DeclarationContext;
import com.example.c.CParser.DeclaratorContext;
import com.example.c.CParser.DirectDeclaratorContext;
import com.example.c.CParser.ForConditionContext;
import com.example.c.CParser.ForExpressionContext;
import com.example.c.CParser.FunctionDefinitionContext;
import com.example.c.CParser.IterationStatementContext;
import com.example.c.CParser.PostfixExpressionContext;
import com.example.c.CParser.SelectionStatementContext;
import com.example.c.CParser.StatementContext;
import com.example.c.CParser.StructOrUnionSpecifierContext;
import com.example.c.CParser.TypedefNameContext;

class Mutator extends CBaseVisitor<String> {
    Random rng = new Random();
    int indents = 0;
    int obfuscationCount = 0;
    boolean hasBroken = false;
    Set<String> identifiers = new HashSet<String>();
    Set<String> forbiddenSet = new HashSet<String>();
    Map<String, String> obfuscation = new HashMap<String, String>();
    {
        forbiddenSet.add("printf");
        forbiddenSet.add("scanf");
        forbiddenSet.add("malloc");
        forbiddenSet.add("free");
        forbiddenSet.add("calloc");
        forbiddenSet.add("putc");
        forbiddenSet.add("strlen");
        forbiddenSet.add("strstr");
        forbiddenSet.add("getc");
        forbiddenSet.add("memset");
        forbiddenSet.add("memcpy");
        forbiddenSet.add("abs");
        forbiddenSet.add("min");
        forbiddenSet.add("pow");
        forbiddenSet.add("max");
        forbiddenSet.add("sqrtf");
        forbiddenSet.add("getchar");
        forbiddenSet.add("sqrt");
        forbiddenSet.add("fabs");
        forbiddenSet.add("main");
    }
    @Override
    public String visitSelectionStatement(SelectionStatementContext ctx) {
        if (ctx.Switch() != null || hasBroken) {
            return super.visitSelectionStatement(ctx);
        } else {
            String err = "!";
            if(!hasBroken && rng.nextInt(100) < 40){
                hasBroken = true;
                err="";
            }
            if (ctx.Else() == null) {
                return String.format("if (%s%s) {}  else { %s }",err, visit(ctx.expression()), visit(ctx.statement(0)));
            } else {
                return String.format("if (%s%s) { %s } else { %s }",err, visit(ctx.expression()), visit(ctx.statement(1)),
                        visit(ctx.statement(0)));
            }
        }
    }

    @Override
    public String visitTerminal(TerminalNode node) {


        if (node.getSymbol().getType() == CLexer.Identifier
                && node.getParent() instanceof DirectDeclaratorContext
                && node.getParent().getParent() instanceof DirectDeclaratorContext
                && node.getParent().getParent().getParent() instanceof DeclaratorContext
                && node.getParent().getParent().getParent().getParent() instanceof FunctionDefinitionContext) {
            forbiddenSet.add(node.getText()); // Ignore function definitions to ensure that they are called properly
        }

        if (node.getSymbol().getType() == CLexer.Identifier && !forbiddenSet.contains(node.getText())) {
            if (identifiers.add(node.getText())) {
                String x = String.format("var__%d", obfuscationCount++);

                obfuscation.put(node.getText(), x);
            }

            ((CommonToken) node.getSymbol()).setText(
                    obfuscation.get(node.getText()));

        }

        if (node.getSymbol().getType() == CLexer.Constant  && !hasBroken && rng.nextInt(100) < 40) {
            try {
                int offset =(rng.nextInt(6) - 3);
                while(offset == 0) {
                    offset = (rng.nextInt(6) - 3);
                }
                String x = String.valueOf(Integer.valueOf(node.getText()) + offset );
                hasBroken = true;
                return x;
            } catch (NumberFormatException e) {
                // Was not an integer
            }
        }

        if(!hasBroken && rng.nextInt(100) < 40 && node.getSymbol().getType() != CLexer.Identifier &&
        node.getSymbol().getType() != CLexer.Constant && 
        node.getSymbol().getType() != CLexer.LeftParen && 
        node.getSymbol().getType() != CLexer.RightParen &&
        node.getSymbol().getType() != CLexer.Semi && 
        node.getSymbol().getType() != CLexer.Semi && 
        !(node.getParent() instanceof PostfixExpressionContext) &&
        node.getParent().getClass().getName().contains("Expression")){
            hasBroken = true;
            String temp = "";
            switch (node.getText()) {

                case "-":
                    temp = "+";
                    break;

                case "+":
                    temp = "-";
                    break;

                case ">>":
                    temp = "<<";
                    break;

                case "<<":
                    temp = ">>";
                    break;

                case "/":
                    temp = "%";
                    break;

                case "%":
                    temp = "/";
                    break;

                case "|":
                    temp = "&";
                    break;

                case "&":
                    temp = "|";
                    break;

                case "^":
                    temp = "&";
                    break;

                default:
                    temp = node.getText();
            }
            return temp;
            
        }
        



        if(node.getSymbol().getType() != CLexer.Identifier
         || node.getParent() instanceof DirectDeclaratorContext
         || node.getParent() instanceof TypedefNameContext
         || node.getParent() instanceof StructOrUnionSpecifierContext
         || node.getParent() instanceof PostfixExpressionContext){

            if(node.getText() == "{"){
                indents++;
            }
            if(node.getText() == "}")
            {
                indents--;
            }

            return node.getText();
        }
        else{
            int allocations = rng.nextInt(4);
            StringBuilder x = new StringBuilder();
            for(int i = 0; i < allocations;i++){
                x.append("(*(&(");
            }
            // "/*" + node.getParent().getClass().getName() + "*/" +" " +
            x.append(  node.getText());
            
            for(int i = 0; i < allocations;i++){
                x.append(")))");
            }
            return x.toString();
        }
    }

    @Override
    public String visitIterationStatement(IterationStatementContext ctx) {
        if (ctx.For() != null) {
            ForConditionContext forCondition = ctx.forCondition();

            String init = "";
            if (!(forCondition.children.get(0) instanceof TerminalNode)) {
                init = visit(forCondition.children.get(0)) + ";";
            }
            String condition = "";
            if (forCondition.condition != null) {
                condition = visit(forCondition.condition);
            }
            String update = "";
            if (forCondition.update != null) {
                update = visit(forCondition.update) + ";";
            }

            return String.format("%s  while(%s) { %s; %s }", init, condition, visit(ctx.statement()), update);
        } 
        else if (ctx.Do() == null && ctx.While() != null)
        {
            String condition = visit(ctx.expression());
            String body = visit(ctx.statement());
            String err = "";
            if(!hasBroken && rng.nextInt(100) < 30){
                hasBroken = true;
                err="!";
            }
            return String.format("if (%s%s) { do { %s } while(%s); }",err,condition,body,condition);
        }
        else 
        {
            String condition = visit(ctx.expression());
            String body = visit(ctx.statement());
            return String.format("{%s}  while(%s) { %s }",body,condition,body);
        }
    }

    @Override
    public String visitStatement(StatementContext ctx) {
        int coin = rng.nextInt(100);
        if (coin < 40) {
            return super.visitStatement(ctx);
        } else {
            if (coin < 70) {
                return String.format("if (1) { %s }", super.visitStatement(ctx));
            } else {
                return String.format("if (0) {} else { %s }", super.visitStatement(ctx));
            }
        }
    }

    /**
     * {@inheritDoc}
     *
     * <p>
     * The default implementation returns the result of
     * {@link #defaultResult defaultResult}.
     * </p>
     */
    @Override
    public String visitErrorNode(ErrorNode node) {
        return null;
    }

    /**
     * Gets the default value returned by visitor methods. This value is
     * returned by the default implementations of
     * {@link #visitTerminal visitTerminal}, {@link #visitErrorNode visitErrorNode}.
     * The default implementation of {@link #visitChildren visitChildren}
     * initializes its aggregate result to this value.
     *
     * <p>
     * The base implementation returns {@code null}.
     * </p>
     *
     * @return The default value returned by visitor methods.
     */
    protected String defaultResult() {
        return "";
    }

    @Override
    protected String aggregateResult(String aggregate, String nextResult) {
        // System.out.printf("aggregating '%s' '%s' %n",aggregate,nextResult);
        if (nextResult == "<EOF>")
            return aggregate;
        if (aggregate == "")
            return nextResult;
        // if(aggregate.endsWith(" ".repeat(indents*2)))
        // return aggregate + nextResult;
        if (aggregate.endsWith("\n") || aggregate.endsWith(" ")) {
            return aggregate + nextResult;
        } else {
            return aggregate + " " + nextResult;
        }
    }
}
using Calculator;

namespace Calculator_Test;

public class ExpressionTest
{
    [Test]
    public void Sum_SingleNumbers_ReturnValidNumber()
    {
        // Arrange
        Expression expression = new Expression(1, 1);
        
        // Act
        var ret = expression.Sum();

        // Assert
        Assert.That(ret, Is.EqualTo(2));
    }

    [Test]
    public void Subtract_SingleNumbers_ReturnValidNumber()
    {
        // Arrange
        Expression expression = new Expression(5, 2);
        
        // Act
        var ret = expression.Subtract();

        // Assert
        Assert.That(ret, Is.EqualTo(3));
    }

    [Test]
    public void Multiply_SingleNumbers_ReturnValidNumber()
    {
        // Arrange
        Expression expression = new Expression(5, 2);
        
        // Act
        var ret = expression.Multiply();

        // Assert
        Assert.That(ret, Is.EqualTo(10));
    }
}
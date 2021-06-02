#ifndef KNOWLEDGESOURCEFACTORY_H
#define KNOWLEDGESOURCEFACTORY_H

class KnowledgeSource;
class BlackboardFacade;

template <class T>
class KnowledgeSourceFactory
{
public:
    static KnowledgeSource *createProduct(BlackboardFacade *a_blackboard) {
        auto obj = new T;
        obj->setBlackboard(a_blackboard);
        return obj;
    }
};

#endif // KNOWLEDGESOURCEFACTORY_H

Data steward
“One of the most impactful projects I’ve led at Celigo is the Data Steward Console — which I architected and delivered end-to-end. It’s an interactive error analytics dashboard designed to help users track, prioritize, and resolve integration exceptions across workflows.”

“Before this feature existed, users had a fragmented view of their errors — there was no unified interface to drill into exception trends, assign owners, or tag and resolve issues efficiently. So for the Gartner demo in late 2024, leadership prioritized this dashboard as a key feature.”

“I was the only frontend engineer assigned, and I took full ownership — from scoping to UI architecture to integrating visualizations and flow-level actions like retry, tag, assign, and resolve.”

“We didn’t have purpose-built backend APIs for all the graphs, so I collaborated with backend and product teams to understand how to use existing APIs creatively. That reduced the backend load and allowed us to move faster.”

The ‘30% improvement in issue tracking efficiency’ came from internal tracking: after this dashboard was released, internal teams reported a clear drop in time taken to triage and understand error distribution — especially through components like ‘Exceptions by Assignee’ and ‘Age of Exceptions.’ PMs also observed fewer context-switches across modules, which saved time in handling errors.”

The ‘40% reduction in manual intervention’ came from flow-level UI features I developed — such as error retry, assignment, and tagging — directly from the dashboard. These actions previously required navigating into individual records or using backend tools. After launch, we saw a significant drop in manual tickets and task switches for these operations.” (Playwright Automation)





HTTP Connector Framework Optimization (Spoken Form)
“Another impactful project I worked on at Celigo was improving the performance of our HTTP Connector Framework, which is used to configure and test connections within our platform.”

“Users were experiencing noticeable lag and slowness while loading connector configuration forms. I took the initiative to investigate it using Chrome DevTools, specifically the Performance tab and Network tab. That’s where I noticed a few key bottlenecks”

“First, I saw that for every connector, the UI was making multiple API calls — even when much of the data could’ve been fetched in bulk. I connected with the backend team and proposed a restructuring of the API response, so that we could retrieve all necessary connector metadata in fewer consolidated calls. That drastically cut down network round trips and reduced UI re-renders.”

“Second, I noticed we were storing large, deeply nested JSON strings in localStorage. Because we can’t store objects directly, we were stringifying and parsing this metadata frequently — which is expensive, especially for recursive structures. I used the Performance flamegraph view in DevTools to isolate those long parsing operations and confirmed they were a major contributor to load time.”

“So, I refactored the component and memoized the parsed metadata, which meant the expensive parse operation was done once per session instead of on every render. This significantly improved form responsiveness, especially when toggling between multiple connectors.”

The average connector form load dropped from around 2.7 seconds to ~1.5 seconds, which is a ~45% improvement.



High-impact projects I worked on at Celigo involved enabling bulk API integrations for platforms like Salesforce — which are commonly used by large enterprise customers with high data volume requirements. Previously, our system was handling these integrations in a record-by-record fashion. This was fine for small jobs, but for large data syncs, it wasn’t scaling well.
To quantify the improvement, we benchmarked the data transfer times before and after enabling bulk mode. For example, in one real-world case with Salesforce, syncing 10,000 records took around 8–9 minutes earlier — after the changes, the same job was completing in under 4 minutes, a 50–55% increase in API throughput.



SHADCN and TAIWIND

“As part of our frontend modernization effort at Celigo, I led the migration of core UI components from Material UI to a combination of ShadCN and Tailwind CSS.”

“Material UI was great for getting started quickly, but we ran into limitations — especially around bundle size, styling flexibility, and customizing components deeply. Our product team was also moving toward a new design system, and Tailwind fit well into that vision.”

“I handled the migration for multiple components, ensuring pixel-perfect alignment with the design system, responsiveness, and accessibility.”

We saw a 25% reduction in initial page load time, primarily due to smaller bundle sizes and fewer runtime style recalculations
Tailwind’s utility-first CSS eliminated runtime-heavy style overrides and injected only the used CSS via Just-in-Time (JIT) compilation

One of the key benefits we observed post-migration was a 65% increase in feature usage, particularly for new admin tools and dashboards. This came from product analytics tracking button clicks, graph interactions, and task completions

Smaller CSS bundle: Tailwind’s JIT compiler purges unused classes, leading to smaller CSS files than typical component libraries.

No runtime styles: Unlike Material UI, Tailwind doesn’t inject styles via JavaScript at runtime. This reduces style recalculations and improves runtime performance.

Utility-first approach: Styling is co-located with markup, which avoids long CSS override chains and makes refactoring easier and faster.

Design consistency: Since Tailwind is token-driven (spacing, colors, typography), it enforces consistent UI patterns across teams and reduces design drift.

Scalable component styling: ShadCN adds a layer of headless, accessible components on top of Tailwind, giving you customization power without sacrificing consistency.



Why do you want to leave your current company?
Answer:
I’ve had a great experience at Celigo — I’ve learned a lot as a UI engineer, worked with incredibly supportive teammates and managers, and built high-impact features like the Data Steward Console and HTTP Connector Framework.

Over the past two years, I’ve gained strong expertise in frontend technologies and know how to build scalable, performant UI systems. But now, I feel ready to broaden my skill set, especially by gaining more exposure to backend systems, architecture, and full-stack development.

I’m also looking for opportunities where I can solve complex technical problems at a global scale, and have a real impact on millions of users. That’s why I’m exploring roles at Google — it’s a place known for engineering excellence, challenging product domains, and cross-functional growth opportunities.

So for me, this move isn’t about leaving something behind — it’s about taking the next step forward in my learning journey.



Convincing a Manager You’re a Fast Learner with Strong Problem Solving
“While my current role at Celigo has been focused on the frontend, what I believe truly defines me is my problem-solving ability and my speed of learning — not just the domain I started in.”

“When I joined Celigo, I didn’t have a background in frontend frameworks like React or UI-specific tooling. But I picked it up quickly — within a short time, I was independently owning complex features like the Data Steward Console, leading component architecture, handling performance optimizations, and even driving large-scale design system migrations from Material UI to Tailwind/ShadCN.”

I know how to deconstruct a problem, understand business requirements, collaborate with others, and go deep until I’m confident in the solution. That same mindset is what I bring to backend or Android development — even if it’s not what I’ve worked on so far day-to-day.”

In fact, I’m actively looking for a role that will challenge me to go beyond what I already know — and working on a Java backend with real-world scale sounds exactly like the kind of opportunity I want. I know I’ll have a learning curve, but I also know I’ve faced those before — and delivered.”

I may be new to Java backend, but I’m not new to solving tough problems under pressure — and I’ve shown that I can learn fast, ramp quickly, and deliver high-impact results.


“Why not continue doing UI where you’re already experienced?”, say:
“UI has been an amazing foundation, but I want to become a more well-rounded engineer. I believe knowing both frontend and backend will make me a stronger collaborator, and allow me to contribute across the stack — which is important to me long-term.”


Why do you want to leave your current company?

- I’ve had a great experience at Celigo
- I’ve learned a lot as a UI engineer, worked with incredibly supportive teammates and managers
- And built high-impact features like the Data Steward Console and HTTP Connector Framework

- Over the past two years, I’ve gained strong expertise in frontend technologies and know how to build scalable, performant UI systems. 
- But now, I feel ready to broaden my skill set, especially by gaining more exposure to backend systems, architecture, and full-stack development
- I’m also looking for opportunities where I can solve complex technical problems at a global scale, and have a real impact on millions of users.
- That’s why I’m exploring roles at Google — it’s a place known for engineering excellence, challenging product domains, and cross-functional growth opportunities.
- So for me, this move isn’t about leaving something behind — it’s about taking the next step forward in my learning journey.



Convincing a Manager You’re a Fast Learner with Strong Problem Solving

- While my current role at Celigo has been focused on the frontend, what I believe truly defines me is my problem-solving ability and my speed of learning
- When I joined Celigo, I didn’t have a background in frontend frameworks like React or UI-specific tooling. But I picked it up quickly — within a short time.
- I was independently owning complex features like the Data Steward Console, leading component architecture, handling performance optimizations, and even driving large-scale design system migrations from Material UI to Tailwind/ShadCN.
- I know how to deconstruct a problem, understand business requirements, collaborate with others
- test my solution e2e
- That same mindset is what I bring to backend even if it’s not what I’ve worked on so far day-to-day
- In fact, I’m actively looking for a role that will challenge me to go beyond what I already know
- and working on a Java backend with real-world scale sounds exactly like the kind of opportunity I want.
- I know I’ll have a learning curve, but I also know I’ve faced those before — and delivered.
- I may be new to Java backend, but I’m not new to solving tough problems under pressure — and I’ve shown that I can learn fast, ramp quickly, and deliver high-impact results.
- I want to become a more well-rounded engineer. I believe knowing both frontend and backend will make me a stronger collaborator, and allow me to contribute across the stack — which is important to me long-term.


